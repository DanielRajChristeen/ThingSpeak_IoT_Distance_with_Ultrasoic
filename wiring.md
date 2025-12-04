
# Wiring Diagram – Ultrasonic Sensor + ESP32

## HC-SR04 → ESP32 Pin Map
- VCC → 5V
- GND → GND
- Trig → GPIO 5
- Echo → GPIO 18 (via 10k + 20k divider)

## Voltage Divider Details
5V Echo → 3.3V safe levels

HC-SR04 Echo → 10k → Node → 20k → GND  
ESP32 Echo reads from *Node*.

This prevents damaging the ESP32 input pin, which cannot tolerate 5V.

Diagram:
5V ---[10k]----●----[20k]---- GND  
                    │  
                 ESP32 (GPIO18)
