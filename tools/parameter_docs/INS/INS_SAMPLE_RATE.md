---
layout: parameter
name: INS_SAMPLE_RATE
display_name: IMU Sample Rate
description: Selects the internal sampling frequency for the IMU sensor drivers.
default_value: 1
range: 1 3
units: kHz
group: INS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_InertialSensor/AP_InertialSensor.cpp
---

# IMU Sample Rate (INS_SAMPLE_RATE)

## Description
`INS_SAMPLE_RATE` defines how fast the flight controller talks to the accelerometer and gyroscope chips.

A higher sample rate allows for better vibration filtering (aliasing prevention) and more responsive flight control. However, it also increases the CPU load on the autopilot.

*   **1: 1 kHz (Standard).** Suitable for most F4 and F7 flight controllers.
*   **2: 2 kHz.**
*   **3: 8 kHz.** Only recommended for high-performance H7 flight controllers and high-end IMUs (like ICM series).

## Tuning & Behavior
*   **Default:** 1 kHz.
*   **Recommendation:** Only increase this if your CPU load (`PM_CPU_Usage`) remains low (below 50%) and you are looking for the absolute best flight performance on a racing quad.