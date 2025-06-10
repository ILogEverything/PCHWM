# PCHWM

## Description

SensorMonitor is a system designed to monitor PC hardware parameters. Information is acquired through **[OpenHardwareMonitor](https://github.com/openhardwaremonitor/openhardwaremonitor)** and **[LibreHardwareMonitor](https://github.com/LibreHardwareMonitor/LibreHardwareMonitor)**, already included via their respective DLLs, and transmitted via USB (COM port) to an Arduino, which displays it on a 20x4 LCD screen.

## Features

- **Real-time monitoring** of PC hardware parameters.
- **Display on a 20x4 LCD screen**.
- **Communication via USB (COM port) with Arduino**.

## Hardware Requirements

- **Arduino**.
- **20x4 LCD display**.
- **I2C module for the display**.

## Installation and Configuration

1. **Prepare the hardware**: Connect Arduino and the 20x4 LCD display with the I2C module.
2. **Upload the firmware to Arduino** using the Arduino IDE with the required libraries.
3. **Run the Windows software**, which includes the OpenHardwareMonitor and LibreHardwareMonitor DLLs with no installation required (It takes a few seconds to start, it shows no signs of life, it's normal because it's scanning the system).
4. **In the program**, select the component to monitor, you can choose up to two sensors. For each sensor, you can set the preferred unit of measurement.

## Libraries Used

- For Arduino: Wire.h, LiquidCrystal_I2C.h

## License

Custom Non-Commercial License (Strict)
Copyright (c) 2025 Giampiero

1. License Grant

This software is provided free of charge and may be used strictly for personal, non-commercial purposes only.  
Any commercial use, resale, redistribution, or integration into other systems or products is strictly prohibited  
without the explicit written consent of the author.

2. Restrictions

- The executable file may not be modified, disassembled, decompiled, reverse-engineered, or analyzed in any form.  
- The software may not be incorporated into, linked with, or embedded in any other system, application, or framework  
  without the author's explicit written permission.  
- Redistribution is permitted **only** in its original, unmodified form, and strictly for non-commercial use.

3. Disclaimer of Warranty

This software is provided "as is", without any express or implied warranties, including but not limited to merchantability,  
fitness for a particular purpose, or non-infringement. Use of this software is entirely at your own risk.

4. Limitation of Liability

In no event shall the author be held liable for any loss, damage, data corruption, malfunction, or legal claims arising from  
the use, misuse, or inability to use this software.

---

For commercial licensing or other inquiries, please contact the author directly.
