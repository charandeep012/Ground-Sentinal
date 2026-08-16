# Ground Sentinal

### Robotic Metal Hazard Detection System for Construction-Site Safety

Ground Sentinal is a Bluetooth-controlled robotic inspection vehicle designed to improve safety at construction sites by detecting hazardous metallic debris such as sharp metal fragments, nails, screws, and wires.

The system uses an Arduino UNO as the central controller, combining wireless robotic control with metal detection. When a metallic object is detected, the system is designed to stop the vehicle and activate an audible alert, allowing the operator to identify potential hazards while maintaining a safer distance from the inspection area.

---

## 🎯 Objectives

* Reduce the need for manual inspection of potentially hazardous ground areas.
* Detect metallic debris that may pose a safety risk to construction workers.
* Enable remote operation of the inspection vehicle through Bluetooth.
* Automatically stop the vehicle when a metallic hazard is detected.
* Provide an immediate audible alert to the operator.

---

## 🚀 Key Features

* Bluetooth-Controlled Navigation – Remotely control the robotic vehicle using a mobile device.
* Metal Hazard Detection – Detect metallic objects present near or beneath the ground surface.
* Automatic Safety Stop – Stop the vehicle when a potential metallic hazard is detected.
* Audible Alert System – Activate a buzzer to notify the operator.
* Real-Time Control – Arduino processes movement commands and sensor signals.
* Modular Design – Hardware components can be extended with additional sensors and monitoring modules.

---

## 🛠️ Technologies & Components

### Software

* C
* Arduino IDE
* Serial Communication

### Hardware

* Arduino UNO
* Bluetooth Module (HC-05)
* Metal Detector Sensor
* L298N Motor Driver
* DC Motors
* Buzzer
* Battery Power Supply
* Robotic Vehicle Chassis

---

## ⚙️ System Architecture

```text
                    Mobile Application
                           │
                        Bluetooth
                           │
                           ▼
                    ┌─────────────┐
                    │  Arduino    │
                    │    UNO      │
                    └──────┬──────┘
                           │
              ┌────────────┴────────────┐
              │                         │
              ▼                         ▼
       Motor Driver               Metal Detector
          L298N                         │
              │                         │
              ▼                         ▼
         DC Motors               Metal Detected
              │                         │
              ▼                    ┌────┴────┐
       Robotic Movement            │         │
                                   ▼         ▼
                                Buzzer    Stop Robot
```

---

## 🔄 Working Principle

1. The operator sends movement commands to the robot through a Bluetooth-enabled mobile application.
2. The Bluetooth module transfers the commands to the Arduino UNO.
3. The Arduino processes the commands and controls the DC motors through the L298N motor driver.
4. While the vehicle moves, the metal detector scans the surrounding ground for metallic objects.
5. When a metallic hazard is detected, the Arduino interrupts normal movement.
6. The vehicle stops and the buzzer is activated to alert the operator.
7. The operator can inspect the detected area and continue operation after the hazard is cleared.

---

## 🔌 Hardware Integration

| Component              | Function                                  |
| ---------------------- | ----------------------------------------- |
| Arduino UNO            | Central controller for the system         |
| HC-05 Bluetooth        | Wireless communication and remote control |
| Metal Detector         | Detects metallic objects                  |
| L298N Motor Driver     | Controls motor direction and speed        |
| DC Motors              | Provides movement to the robotic vehicle  |
| Buzzer                 | Provides an audible hazard alert          |
| Battery                | Powers the robotic system                 |

---

## 📊 Prototype Testing

The original prototype was tested for metal detection, Bluetooth communication, system integration, and power operation.

| Parameter                     | Prototype Result    |
| ----------------------------- | ------------------- |
| Metal detection depth         | 4–6 cm              |
| Bluetooth communication range | 5–10 m              |
| Automatic stopping            | Successfully tested |
| Buzzer alert                  | Successfully tested |
| Continuous operation          | Up to 4 hours       |


---

## 📷 Project Gallery

Add photographs of the actual prototype and testing setup here.

### Prototype
<img width="632" height="354" alt="Screenshot 2026-08-16 233020" src="https://github.com/user-attachments/assets/f05453d2-8a0c-448b-8b36-6047773e1361" />

---

## 🔮 Future Enhancements

* GPS Integration for recording the location of detected hazards.
* Camera Integration for visual verification of detected objects.
* Web/Mobile Dashboard for real-time monitoring and hazard reporting.
* Hazard Logging to maintain a history of detected metallic objects.
* Autonomous Navigation to reduce manual vehicle control.
* Advanced Particulate Sensing for monitoring fine airborne dust, including investigation of suitable methods for detecting metal-containing particulate matter.
* Improved Detection Algorithms for better performance across different ground and environmental conditions.

---

## ⚠️ Current Scope & Limitations

The current prototype focuses on metallic-object detection using a metal detector and is intended as a construction-site safety prototype.

It should not be considered a certified safety or hazard-clearance system. Detection performance can vary depending on object size, depth, soil conditions, electromagnetic interference, and sensor characteristics.

Fine metal dust detection is not currently implemented and would require an additional sensing mechanism and dedicated testing.

---

## 👨‍💻 Project Team

Ground Sentinal was developed as a team project under the Social Innovation in Practice course at CMR College of Engineering & Technology.

### Team Members

* G. Charan Deep Reddy
* R. Nithish Kumar
* A. Manohar Reddy
* P. Sumanasvi
* A. Anisha


---

## 📌 Project Status

Prototype Completed | Construction-Site Safety Application Under Development

The current repository contains the Arduino-based robotic control and metal-detection functionality. Future development will focus on improving hazard detection, monitoring, navigation, and construction-site validation.
