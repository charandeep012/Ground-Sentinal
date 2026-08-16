#include <SoftwareSerial.h>

// ---------------- MOTOR PINS ----------------
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define ENA 9
#define ENB 10

// ---------------- BLUETOOTH ----------------
#define BT_RX 6
#define BT_TX 7

SoftwareSerial Bluetooth(BT_RX, BT_TX);

// ---------------- METAL DETECTOR ----------------
#define METAL_SENSOR 8
#define BUZZER 11

#define SPEED 100

// Change to HIGH if your metal sensor outputs HIGH
// when metal is detected.
#define METAL_ACTIVE LOW

bool hazardDetected = false;


// ---------------- SETUP ----------------
void setup() {

  Serial.begin(9600);
  Bluetooth.begin(9600);

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Metal detector and buzzer
  pinMode(METAL_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);

  // Initially stop the robot
  Stop();

  digitalWrite(BUZZER, LOW);

  Serial.println("GROUND SENTINAL READY");
  Bluetooth.println("GROUND SENTINAL READY");
}


// ---------------- MAIN LOOP ----------------
void loop() {

  // Check for metal hazard
  if (digitalRead(METAL_SENSOR) == METAL_ACTIVE) {

    hazardDetected = true;

    // Immediately stop the robot
    Stop();

    // Activate buzzer
    digitalWrite(BUZZER, HIGH);

    // Send warning
    Serial.println("METAL HAZARD DETECTED!");
    Bluetooth.println("WARNING: METAL HAZARD DETECTED!");

    // Keep the robot stopped
    while (digitalRead(METAL_SENSOR) == METAL_ACTIVE) {

      Stop();
      digitalWrite(BUZZER, HIGH);

      delay(100);
    }

    // Metal no longer detected
    digitalWrite(BUZZER, LOW);

    hazardDetected = false;

    Serial.println("HAZARD CLEARED");
    Bluetooth.println("HAZARD CLEARED");
  }


  // Process Bluetooth commands only when
  // there is no detected hazard
  if (!hazardDetected && Bluetooth.available() > 0) {

    char command = Bluetooth.read();

    Serial.print("Command: ");
    Serial.println(command);

    switch (command) {

      case 'U':
        Forward();
        break;

      case 'D':
        Backward();
        break;

      case 'L':
        Left();
        break;

      case 'R':
        Right();
        break;

      case 'S':
        Stop();
        break;

      default:
        Stop();
        break;
    }
  }
}


// ---------------- FORWARD ----------------
void Forward() {

  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// ---------------- BACKWARD ----------------
void Backward() {

  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// ---------------- LEFT ----------------
void Left() {

  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// ---------------- RIGHT ----------------
void Right() {

  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// ---------------- STOP ----------------
void Stop() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
