---
layout: parameter
title: KDE_NPOLE
name: Number of motor poles
group: KDE
---

# KDE_NPOLE: Number of motor poles

## Description
Sets the number of motor poles (magnetic poles on the bell) to calculate the correct RPM value from the KDECAN ESC telemetry.

## Values
- **Range:** 2 to 255
- **Increment:** 2
- **Default:** 14

## Description
This parameter ensures the RPM reported by your KDE Direct CAN ESCs is accurate. ESCs measure "electrical RPM" based on the commutations. To get physical RPM, the autopilot needs to divide the electrical RPM by half the number of motor poles.

- **Check your motor specs:** Look for "Magnetic Poles" or "Magnet Poles" in your motor's datasheet.
- **Common Values:**
    - 14 (Standard for many heavy-lift motors like KDE Direct)
    - 12, 22, 24, 28 (Other common configurations)

## Source Code
[ardupilot/libraries/AP_KDECAN/AP_KDECAN.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_KDECAN/AP_KDECAN.cpp#L41)

