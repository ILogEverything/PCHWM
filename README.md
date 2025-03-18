# PCHWM

## Description

HWMonitor is a system designed to monitor PC hardware parameters. Information is acquired through **OpenHardwareMonitor** and **LibreHardwareMonitor**, already included via their respective DLLs, and transmitted via USB (COM port) to an Arduino, which displays it on a 20x4 LCD screen.

## Features

- **Real-time monitoring** of PC hardware parameters.
- **Display on a 20x4 LCD screen**.
- **Communication via USB (COM port) with Arduino**.
- **Compatible with Arduino and Windows software**.

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

1. License Grant

This software is provided free of charge and may be used for personal and non-commercial purposes only. Any commercial use, distribution, or resale of this software is strictly prohibited without the explicit written consent of the author.

2. Restrictions

The executable file may not be modified, decompiled, reverse-engineered, or analyzed in any way.

The software may not be incorporated into any other software or system without explicit permission from the author.

Redistribution of the software is allowed only in its original, unmodified form and for non-commercial purposes.

3. Disclaimer of Warranty

This software is provided "as is", without any express or implied warranties. The author assumes no responsibility for any damages, direct or indirect, that may arise from the use of this software.

4. Liability Limitation

By using this software, you agree that the author is not liable for any issues, malfunctions, data loss, or damages caused by its use.

5. Voluntary Donations

This software is provided free of charge. If you find it useful and wish to support the project, you may make a voluntary donation via PayPal (link in the sw). Donations do not grant additional rights or privileges.
