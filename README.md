# ⚡ NE555 PWM Signal Generator

<p align="center">

![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/platform-ESP32-blue?style=for-the-badge)
![Type](https://img.shields.io/badge/type-Analog%20%2B%20Digital-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/status-Active-success?style=for-the-badge)

</p>

---

## 🌑 Overview

A modern **NE555 astable PWM generator** used to generate square waves and measure frequency & duty cycle using an ESP32.

<p align="center">
⚡ Generate → 📡 Measure → 📊 Analyze → 🖥️ Display
</p>

---

## 🧾 Table of Contents

* ⚡ Overview
* ⚙️ Features
* 🧠 How It Works
* 🔌 Circuit
* 🧷 NE555 Pinout
* 📊 Signal Characteristics
* 🔗 ESP32 Connections
* 🚀 Use Cases
* ⚠️ Notes
* 👨‍💻 Author

---

## ⚙️ Features

| Feature                  | Description            |
| ------------------------ | ---------------------- |
| 🎛️ Adjustable frequency | Potentiometer control  |
| ⚡ PWM output             | Square wave generation |
| 🔌 ESP32 compatible      | 3.3V logic support     |
| 📊 Real-time measurement | Frequency & duty cycle |
| 🖥️ OLED support         | Optional display       |

---

## 🧠 How It Works

The NE555 operates in astable mode:

* Capacitor charges → output HIGH
* Capacitor discharges → output LOW
* Potentiometer controls timing

Result: adjustable PWM signal

---

## 🔌 Circuit

### Tinkercad Simulation

[check here](https://www.tinkercad.com/things/1M5ezg14CPK-copy-of-copy-of-copy-of-magnificent-snaget-tumelo)

# ESP32 OSCILLOSCOPE 
[](https://github.com/Koxalk/ne555-esp32-pwm-analyzer/blob/main/IMG_20260417_163247131.jpg)

### Timing Network

```
      VCC
       │
      [R1]
       │
       ├──── Pin 7
       │
 [Potentiometer]
       │
       ├──── Pin 6 + Pin 2
       │
      [ C ]
       │
      GND
```

---

## 🧷 NE555 Pinout

| Pin | Name      | Function           |
| --- | --------- | ------------------ |
| 1   | GND       | Ground             |
| 2   | Trigger   | Threshold input    |
| 3   | Output    | PWM output → ESP32 |
| 4   | Reset     | VCC                |
| 5   | Control   | Optional capacitor |
| 6   | Threshold | Connected to Pin 2 |
| 7   | Discharge | Timing control     |
| 8   | VCC       | Power supply       |

---

## 📊 Signal Characteristics

| Parameter  | Value             |
| ---------- | ----------------- |
| Type       | Square wave (PWM) |
| Voltage    | 0V – VCC          |
| Frequency  | Adjustable        |
| Duty cycle | Adjustable        |

---

## 🔗 ESP32 Connections

### Power

* VCC → 3.3V / 5V
* GND → Common ground

### Signal

* GPIO 14 → NE555 output

### Optional

* GPIO 13 → Freeze
* GPIO 12 → Zoom

### OLED (I2C)

* SDA → GPIO 21
* SCL → GPIO 22

⚠️ Use voltage divider if NE555 runs at 5V

---

## 🚀 Use Cases

* PWM signal testing
* Embedded systems learning
* Frequency measurement
* Electronics prototyping

---

## ⚠️ Notes

* ESP32 = 3.3V logic only
* Always share common GND
* Add decoupling capacitor
* Protect GPIO from 5V

---

## 👨‍💻 Author

Electronics & Embedded Systems Project
NE555 + ESP32 Signal Generator

---

⚡ Built for learning and experimentation ⚡
