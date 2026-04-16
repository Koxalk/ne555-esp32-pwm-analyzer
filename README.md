# NE555 PWM Signal Generator

![License](https://img.shields.io/badge/license-MIT-green)
![Platform](https://img.shields.io/badge/platform-ESP32-blue)
![Electronics](https://img.shields.io/badge/type-Analog%20%2B%20Digital-orange)
![Status](https://img.shields.io/badge/status-Active-success)

## 📖 Overview

This project demonstrates a simple **NE555 timer configured in astable mode** to generate a **PWM (square wave) signal**.

The generated signal can be used for testing and is read by a microcontroller (e.g., ESP32) to measure:

* Frequency (Hz)
* Duty Cycle (%)

An OLED display can be used to visualize the signal.

---

## ⚙️ Features

* Adjustable frequency using potentiometer
* PWM (square wave) output
* Compatible with ESP32 and other microcontrollers
* Real-time signal measurement (frequency & duty cycle)

---

## 🧠 How It Works

The **NE555 timer** operates in **astable mode**, continuously switching between HIGH and LOW states.

* The timing is controlled by resistors and a capacitor
* A potentiometer adjusts the charge/discharge time
* This directly affects frequency and duty cycle

---

## 🔌 Wiring Diagram

👉 **Tinkercad Schematic (NE555 only):**
[https://www.tinkercad.com/things/1M5ezg14CPK-copy-of-copy-of-copy-of-magnificent-snaget-tumelo](https://www.tinkercad.com/things/1M5ezg14CPK-copy-of-copy-of-copy-of-magnificent-snaget-tumelo)

### NE555 Pin Connections (Clean Layout)

```
Pin 1  → GND
Pin 2  → Connected to Pin 6 (Trigger)
Pin 3  → OUTPUT → ESP32 GPIO 14
Pin 4  → VCC
Pin 5  → Optional capacitor to GND
Pin 6  → Connected to Pin 2 (Threshold)
Pin 7  → Discharge → Resistor → VCC
Pin 8  → VCC
```

### Timing Components

```
VCC
 |
[R1]
 |
 +------ Pin 7 (Discharge)
 |
[Potentiometer]
 |
 +------ Pin 6 & Pin 2
 |
[C]
 |
GND

-------> Pin 7 (Discharge)
|
[Potentiometer]
|
+-------> Pin 6 (Threshold)
|         Pin 2 (Trigger)
|
[C]
|
GND

Pin 1 → GND
Pin 2 → Threshold
Pin 3 → OUTPUT → ESP32 GPIO
Pin 4 → VCC
Pin 5 → (optional capacitor to GND)
Pin 6 → Threshold
Pin 7 → Discharge
Pin 8 → VCC

```

-------> Pin 7 (Discharge)
         |
        [Potentiometer]
         |
         +-------> Pin 6 (Threshold)
         |         Pin 2 (Trigger)
         |
        [C]
         |
        GND

Pin 1 → GND
Pin 2 → Threshold
Pin 3 → OUTPUT → ESP32 GPIO
Pin 4 → VCC
Pin 5 → (optional capacitor to GND)
Pin 6 → Threshold
Pin 7 → Discharge
Pin 8 → VCC
```

---

## 🖼️ Circuit Preview

> Add your own circuit image here (screenshot from Tinkercad or real setup)

---

## 📊 Signal Characteristics

| Parameter   | Description       |
| ----------- | ----------------- |
| Signal Type | Square Wave (PWM) |
| Voltage     | 0V – VCC          |
| Frequency   | Adjustable        |
| Duty Cycle  | Adjustable        |

---

## 🔗 ESP32 Connection

### Pin Mapping

* **VCC** → 3.3V or 5V (depending on setup)
* **GND** → Common ground (shared with NE555)
* **GPIO 14** → NE555 Output (signal input)
* **GPIO 13** → Freeze function (hold measurement)
* **GPIO 12** → Zoom function (adjust display scale)
* **GPIO 21 (SDA)** → OLED
* **GPIO 22 (SCL)** → OLED

### Notes

* Ensure common GND between NE555 and ESP32
* If NE555 runs at 5V, use a voltage divider before GPIO 14
* Buttons (freeze/zoom) should use pull-down or pull-up resistors

---

## 🚀 Use Cases

* PWM signal testing
* Microcontroller interrupt testing
* Frequency measurement projects
* Duty cycle analysis

---

## ⚠️ Notes

* ESP32 operates at **3.3V logic**
* If NE555 runs at 5V, use a voltage divider
* Add decoupling capacitor for stable operation

---

## 📜 License

This project is licensed under the MIT License.

---

## 👨‍💻 Author

Created as an electronics & embedded systems project using NE555 and ESP32.


## 👨‍💻 Author
Created as an electronics & embedded systems project using NE555 and ESP32.

```
