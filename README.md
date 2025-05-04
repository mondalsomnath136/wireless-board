# ESP8266 4-Relay Controller (AP Mode with IR Support)


This project allows you to control **four relays** using an **ESP8266 (NodeMCU)** in **self-hosted access point mode**. No external Wi-Fi router is required. Additionally, it supports **IR remote control** to toggle each relay with specific IR codes.

## Features 🚀
- **Standalone Wi-Fi Access Point** (No external router needed)
- **Web API for 4-Relay Control**
- **IR Remote Support to Toggle Each Relay**
- **Simple & Lightweight Code**
- **Perfect for Local IoT Projects**

## Hardware Requirements 🛠️
- **NodeMCU ESP8266**
- **4-Channel Relay Module**
- **IR Receiver Module (e.g., TSOP1838)**
- **Jumper Wires**
- **5V Power Supply**

## Circuit Diagram ⚡
| ESP8266 Pin | Component         |
|------------|------------------|
| D1 (GPIO5) | IN1 (Relay 1)     |
| D2 (GPIO4) | IN2 (Relay 2)     |
| D6 (GPIO12)| IN3 (Relay 3)     |
| D7 (GPIO13)| IN4 (Relay 4)     |
| D5 (GPIO14)| IR Receiver OUT   |
| GND        | GND               |
| 3.3V       | VCC (Relays/IR)   |

## Installation 📥
1. **Flash the Code**
   - Use **Arduino IDE** or **PlatformIO**
   - Install the **ESP8266 Board Package**
   - Install required libraries:
     - `IRremoteESP8266`
   - Upload the code to your ESP8266

2. **Connect to Wi-Fi**
   - After flashing, the ESP8266 creates a Wi-Fi access point.
   - Connect to `ESP8266_Relay` (Password: `12345678`)

3. **Control Relays via API**
   - Open a browser and enter:
     - `http://192.168.4.1/relay1/on` → Turns **Relay 1 ON**
     - `http://192.168.4.1/relay1/off` → Turns **Relay 1 OFF**
     - `http://192.168.4.1/relay2/on` → Turns **Relay 2 ON**
     - `http://192.168.4.1/relay2/off` → Turns **Relay 2 OFF**
     - `http://192.168.4.1/relay3/on` → Turns **Relay 3 ON**
     - `http://192.168.4.1/relay3/off` → Turns **Relay 3 OFF**
     - `http://192.168.4.1/relay4/on` → Turns **Relay 4 ON**
     - `http://192.168.4.1/relay4/off` → Turns **Relay 4 OFF**

## IR Remote Functionality 🎮
- When the IR receiver detects specific IR signals:
  - `0xFFA25D` → Toggle Relay 1 ON/OFF
  - `0xFF629D` → Toggle Relay 2 ON/OFF
  - `0xFFE21D` → Toggle Relay 3 ON/OFF
  - `0xFF22DD` → Toggle Relay 4 ON/OFF

> Replace these codes with your own IR remote's codes if needed (view them in Serial Monitor).

## Example API Calls 📡
Use **cURL** or your browser:
```bash
curl http://192.168.4.1/relay1/on
curl http://192.168.4.1/relay4/off
```

## License 📜
This project is licensed under the **Creative Commons Attribution-NonCommercial 4.0 International**.

## Author ✨
Developed by **Somnath Mondal**.

---
**Control your relays with the click of a button or a press of a remote — anywhere, anytime! 🔌📡**
