# ThingSpeak IoT – Ultrasonic Distance Visualization using ESP32

<img src="https://github.com/DanielRajChristeen/ThingSpeak_IoT_Distance_with_Ultrasoic/blob/27f16d978b1c904a016721f7400877db45c42198/images/circuit_demo.jpeg">

This project demonstrates a complete IoT data pipeline using an **ESP32 Dev Kit V1**, **HC-SR04 Ultrasonic Sensor**, and **ThingSpeak Cloud** for real-time distance visualization.  
Two graphs are included:
- ThingSpeak's built-in live chart  
- A MATLAB-powered custom analytical plot  

---

## 🚀 Features

- Ultrasonic distance measurement (HC-SR04)
- Real-time data upload every 15 seconds
- Cloud visualization via ThingSpeak
- MATLAB analytics plot for deeper insight
- Clean, modular ESP32 firmware
- Debug-safe sensor code
- Fully documented wiring and configuration

---

## 🛠 Hardware Requirements

- ESP32 Dev Kit V1
- HC-SR04 Ultrasonic Sensor
- Jumper wires
- Breadboard
- **Voltage Divider (Echo pin → 3.3V safe level)**  
  - 10kΩ + 20kΩ resistor pair

---

## 🔌 Pin Connections

| HC-SR04 Pin | ESP32 Pin |
|-------------|-----------|
| VCC         | 5V        |
| GND         | GND       |
| TRIG        | GPIO 5    |
| ECHO        | GPIO 18 (via 10k+20k divider) |

> **NOTE:** Swapping Trigger and Echo pins will result in a constant `0.00 cm`.  
Double-check wiring if distance stays zero.

---

## 🌐 ThingSpeak Setup

1. Create a new channel  
2. Enable **Field 1 → DISTANCE_CM**  
3. Copy:
   - **Channel ID**
   - **Write API Key**
   - **Read API Key** (for MATLAB plots)

---

## 📡 ESP32 Code

Full source: `src/esp32_ultrasonic_thingspeak.ino`


---

## 📊 MATLAB Visualization Script

File: `matlab/distance_plot.m`

---

## 🐞 Common Issues

| Problem                | Solution                     |
| ---------------------- | ---------------------------- |
| Always 0 cm            | Trigger/Echo pins swapped    |
| Random spikes          | Add smoothing / noise filter |
| No ThingSpeak updates  | Respect 15s rate limit       |
| ESP32 not reading echo | Check voltage divider        |

---

## 📜 License

MIT License (provided in repository)

---

## ⭐ Future Enhancements

* Buzzer alert for close-distance threshold
* MQTT version for real-time updates
* Email alerts via MATLAB Analysis
* OLED screen for local display

---

## 👨‍💻 Author

**Daniel Raj C**

IoT & Embedded Engineering Enthusiast

---
