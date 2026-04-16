# 📈 ESP32 Oscilloscope Project

<p align="center">

![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/platform-ESP32-blue?style=for-the-badge)
![Type](https://img.shields.io/badge/type-Digital%20Oscilloscope-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/status-Active-success?style=for-the-badge)

</p>

---

## 🌑 Overview

A **low-cost digital oscilloscope system** based on the **ESP32**, capable of reading analog signals and visualizing waveforms in real time.

It is designed for educational and electronics prototyping use.

<p align="center">
📡 Signal Input → ⚡ ADC Sampling → 📊 Processing → 🖥️ Visualization
</p>

---

## 🧾 Table of Contents

* Overview
* Features
* How It Works
* Hardware Setup
* Circuit Diagram
* Signal Flow
* ESP32 Pin Mapping
* Display / UI
* Use Cases
* Limitations
* Author

---

## ⚙️ Features

| Feature                  | Description              |
| ------------------------ | ------------------------ |
| 📡 Analog signal input   | Reads external waveforms |
| 📊 Real-time plotting    | Live waveform display    |
| ⚡ ESP32 ADC sampling     | Fast analog read         |
| 🖥️ OLED / TFT support   | Optional visualization   |
| 🔄 Adjustable time scale | Zoom in/out signal       |

---

## 🧠 How It Works

The system uses the ESP32 ADC to sample incoming analog signals:

* Signal enters ADC pin
* ESP32 samples at fixed intervals
* Data is buffered
* Waveform is plotted on display or serial plotter

---

## 🔌 Hardware Setup

### Required Components

* ESP32 development board
* Input signal source (e.g. NE555, function generator)
* Optional OLED (SSD1306) or TFT display
* Resistors for voltage protection

---

## ⚠️ Important Input Protection

ESP32 ADC max voltage = **3.3V**

👉 If input signal > 3.3V, use voltage divider:

```
Vin ──[ R1 ]──┬──→ ESP32 ADC Pin
              |
             [R2]
              |
             GND
```

---

## 🔌 ESP32 Pin Mapping

| Function      | GPIO          |
| ------------- | ------------- |
| Signal Input  | GPIO 34 (ADC) |
| Freeze Button | GPIO 13       |
| Zoom Button   | GPIO 12       |
| OLED SDA      | GPIO 21       |
| OLED SCL      | GPIO 22       |

---

## 📊 Signal Flow

```
Analog Signal
     ↓
Voltage Protection (Divider)
     ↓
ESP32 ADC Sampling
     ↓
Buffer / Processing
     ↓
Display (OLED / Serial Plot)
```

---

## 🖼️ Circuit Diagram

📌 Add your images here:

* ![Circuit Setup](images/circuit.png)
* ![Breadboard](images/breadboard.png)
* ![Final Build](images/final.png)

---

## 📈 Display / UI

* Waveform plotted in real time
* Optional scaling (zoom in/out)
* Freeze frame function
* Serial Plotter support

---

## 🚀 Use Cases

* Electronics signal debugging
* PWM waveform analysis
* Sensor signal visualization
* Embedded systems learning

---

## ⚠️ Limitations

* Limited ADC sampling rate (ESP32 constraint)
* Not suitable for high-frequency RF signals
* Resolution depends on noise and sampling speed

---

## 👨‍💻 Author

Embedded Systems & Electronics Project
ESP32 Digital Oscilloscope

---

⚡ Built for learning, experimentation, and signal visualization