# GasSentrix – Smart Gas Leakage Detection with Automated Response

## Overview
GasSentrix is an IoT-based gas leakage detection system designed to enhance safety in domestic and industrial environments. It continuously monitors gas levels using an MQ gas sensor and provides real-time alerts along with an automated response mechanism.

Upon detecting a gas leak, the system activates visual and audible alerts, sends an instant notification to the user’s mobile device via Telegram, and triggers a servo motor to enable ventilation.

---

## Features
- Real-time gas leakage detection using MQ gas sensor  
- Visual indication using LEDs (Safe / Danger status)  
- Audible alert using buzzer  
- Instant mobile notification via Telegram Bot  
- Automated ventilation using servo motor  
- Wi-Fi enabled monitoring using ESP32  
- Lightweight and low-cost implementation  

---

## Hardware Components
- ESP32 Microcontroller  
- MQ Gas Sensor (MQ-2 / MQ-5)  
- Servo Motor (SG90)  
- Buzzer  
- LEDs (Red, Green)  
- Resistors (220Ω)  
- Breadboard & Jumper Wires  
- 5V Power Supply  

---

## Software & Technologies
- Arduino IDE  
- Arduino C (Embedded C-based)  
- ESP32 Wi-Fi Library  
- HTTP Client Library  
- Telegram Bot API  

---

## Communication Protocols
- **Wi-Fi (IEEE 802.11):** Enables ESP32 to connect to the internet  
- **HTTP/HTTPS:** Used to send GET requests to the Telegram Bot API for real-time alerts  
- **Digital GPIO Interface:** Used for communication between MQ sensor and ESP32  

---

## Working Principle
The MQ gas sensor continuously monitors the surrounding air and provides a digital output based on a preset gas concentration threshold.

- **No Gas Detected:**
  - Green LED remains ON indicating safe conditions  

- **Gas Detected:**
  - Red LED and buzzer are activated  
  - ESP32 sends an alert message to the user via Telegram using HTTP protocol  
  - Servo motor rotates to open a ventilation mechanism  

This ensures both immediate local alerting and remote notification with automated response.

---

## System Limitations
- Threshold-based detection (no exact gas concentration measurement)  
- Requires stable Wi-Fi connection for remote alerts  
- MQ sensor requires warm-up time (~30–60 seconds)  

---

## Future Improvements
- Integration with cloud platforms (Firebase / MQTT)  
- Real-time gas concentration monitoring using analog output  
- Mobile app dashboard  
- PCB design for compact deployment  
- Battery backup system  

---

## Author
**Ashutosh Jain**  
Electronics & Communication Engineering  
Pandit Deendayal Energy University


