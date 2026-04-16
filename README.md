# ⚡📡 ESP32 Signal Lab Suite

## NE555 PWM Generator + Digital Oscilloscope Ecosystem

<p align="center">

![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/platform-ESP32-blue?style=for-the-badge)
![Type](https://img.shields.io/badge/type-Signal%20Processing%20Lab-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/status-Active-success?style=for-the-badge)

</p>

---

## 🌑 Overview

This project is a complete **embedded signal analysis ecosystem** built around the ESP32.

It combines:

* ⚡ **NE555 PWM Signal Generator** (signal source)
* 📈 **ESP32 Digital Oscilloscope** (signal visualization & measurement)

Together they form a low-cost lab for learning, testing, and analyzing electronic signals.

<p align="center">
Signal Generation → Capture → Processing → Visualization
</p>

---

## 🧾 Table of Contents

* Overview
* System Architecture
* NE555 Signal Generator
* ESP32 Oscilloscope
* Integration Setup
* Signal Flow
* Pin Mapping
* Use Cases
* Limitations
* Future Improvements
* Author

---

# 🧠 System Architecture

```
        ┌─────────────────────┐
        │  NE555 Generator    │
        │  (PWM Source)       │
        └─────────┬───────────┘
                  │ Square Wave
                  ▼
        ┌─────────────────────┐
        │ ESP32 Oscilloscope  │
        │ ADC Sampling Engine │
        └─────────┬───────────┘
                  │ Processed Data
                  ▼
        ┌─────────────────────┐
        │ OLED / Serial Plot  │
        │ Waveform Display    │
        └─────────────────────┘
```

---

# ⚡ NE555 PWM Signal Generator

## 📌 Overview

A classic **NE555 timer in astable mode** generating adjustable PWM signals.

## ⚙️ Features

| Feature                  | Description             |
| ------------------------ | ----------------------- |
| 🎛️ Adjustable frequency | Potentiometer control   |
| ⚡ PWM output             | Square wave signal      |
| 🔌 ESP32 compatible      | With voltage protection |
| 📊 Test signal source    | For oscilloscope input  |

## 🔌 NE555 Pinout

| Pin | Function                     |
| --- | ---------------------------- |
| 1   | GND                          |
| 2   | Trigger                      |
| 3   | Output → ESP32 input         |
| 4   | Reset → VCC                  |
| 5   | Control (optional capacitor) |
| 6   | Threshold                    |
| 7   | Discharge (RC network)       |
| 8   | VCC                          |

## ⏱️ Timing Network

```
VCC
 │
[R1]
 │
 ├── Pin 7
 │
[Potentiometer]
 │
 ├── Pin 6 + Pin 2
 │
[C]
 │
GND
```

---

# 📈 ESP32 Digital Oscilloscope

## 📌 Overview

A **real-time waveform visualization system** using ESP32 ADC sampling.

## ⚙️ Features

| Feature                 | Description           |
| ----------------------- | --------------------- |
| 📡 Analog input capture | ADC sampling          |
| 📊 Waveform plotting    | Real-time display     |
| 🔄 Zoom control         | Time scale adjustment |
| ⏸ Freeze function       | Hold waveform         |

## 🔌 ADC Input Protection

⚠️ ESP32 max input = 3.3V

```
Vin ──[R1]──┬── ESP32 ADC
            |
           [R2]
            |
           GND
```

## 🔗 Pin Mapping

| Function     | GPIO    |
| ------------ | ------- |
| Signal Input | GPIO 34 |
| Freeze       | GPIO 13 |
| Zoom         | GPIO 12 |
| OLED SDA     | GPIO 21 |
| OLED SCL     | GPIO 22 |

---

# 🔗 Integration Setup

## ⚡ Connection Flow

* NE555 OUTPUT → ESP32 GPIO 34 (ADC)
* Common GND MUST be shared
* Optional voltage divider if NE555 = 5V

## 📡 Signal Pipeline

```
NE555 PWM Signal
      ↓
Voltage Protection
      ↓
ESP32 ADC Sampling
      ↓
Buffer Processing
      ↓
OLED / Serial Plot Display
```

---

# 🚀 Use Cases

* 📡 PWM signal testing
* 📊 Oscilloscope learning tool
* 🧠 Embedded systems education
* 🔧 Electronics prototyping lab
* ⚙️ Sensor waveform analysis

---

# ⚠️ Limitations

* Limited ADC speed (ESP32 constraint)
* Not suitable for high-frequency RF signals
* Resolution depends on noise + sampling stability
* Basic oscilloscope (not professional grade)

---

# 🔮 Future Improvements

* FFT spectrum analysis 📊
* Higher sampling via I2S ADC mode ⚡
* Web-based oscilloscope UI 🌐
* SD card data logging 💾
* Multi-channel input 📡

---

# 👨‍💻 Author

Embedded Systems & Electronics Project

⚡ NE555 Signal Generator + ESP32 Oscilloscope Ecosystem

---

<p align="center">
⚡ Built for learning • experimentation • embedded signal analysis ⚡
</p>
