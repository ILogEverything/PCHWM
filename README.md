# 🖥️ PCHWM
**Your PC has a voice. Now it has a face.**

**PCHWM** is an elegant, DIY solution for monitoring your PC’s vital signs. Powered by *LibreHardwareMonitor* library, it transforms a simple LCD display into a professional real-time dashboard.

---

## ✨ Features

* **⚡ Zero Distractions:** Keep an eye on temperatures, CPU load, and clock speeds while gaming or working in full-screen mode.
* **📊 Dynamic Graphics:** Real-time visual bar graphs for individual CPU core loads.
* **🔌 Plug & Play Simplicity:** Connect your hardware, run the software, and you're good to go.
* **🌙 Smart Standby:** The display automatically turns off the backlight when the software is closed or the PC shuts down.

---

## 🛠️ Hardware Requirements

You don't need to be a NASA engineer. You just need:
1.  **Arduino** (Uno, Nano, or compatible clones).
2.  **20x4 LCD Display** (The large version, for maximum readability).
3.  **I2C Module** (To connect the display using just 4 wires, with little code modification you can skip this module).

---

## 🚀 Installation & Configuration

1.  **Hardware Setup:** Connect your LCD to the Arduino via the I2C module (VCC, GND, SDA, SCL).
2.  **Firmware:** Flash the provided sketch to your Arduino using the Arduino IDE. 
    * *Required libraries: `Wire.h`, `LiquidCrystal_I2C.h`*
3.  **Windows Software:** Just run the executable. 
4.  **Configuration:** Within the app, select up to two sensors to monitor and set your preferred units of measurement.

---

## 🚀 Sw and Hw Installation

<img width="635" height="270" alt="image" src="https://github.com/user-attachments/assets/2e150f27-3e74-4408-9737-d343788e7541" />

<img width="7200" height="5400" alt="IMG20260422154042" src="https://github.com/user-attachments/assets/5303fb60-df9f-4b1d-85ee-55e7699615a4" />
   
---

## ⚖️ License

**Custom Non-Commercial License (Strict)** *Copyright (c) 2026 Giampiero*

1. **License Grant** This software is provided free of charge and may be used strictly for personal, non-commercial purposes only. Any commercial use, resale, redistribution, or integration into other systems or products is strictly prohibited without explicit written consent.

2. **Restrictions** - The executable file may not be modified, disassembled, decompiled, or reverse-engineered.  
- The software may not be embedded into any other application or framework without permission.  
- Redistribution is permitted **only** in its original, unmodified form for non-commercial use.

3. **Disclaimer of Warranty** This software is provided "as is", without any express or implied warranties. Use at your own risk.

4. **Limitation of Liability** In no event shall the author be held liable for any loss, damage, or malfunction arising from the use of this software.

---

**📧 Contact** For commercial licensing, inquiries, or feedback, please contact the author directly.

---
*Created with care by G. Di Pietrantonio.*
