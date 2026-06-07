---
layout: parameter
name: RNGFND_POS
display_name: Rangefinder Position Offset (Sensor 1)
description: The 3D position of the sensor relative to the vehicle center of gravity.
default_value: 0
range: -5 5
units: m
group: RNGFND
visual_asset_id: antenna_offset_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L132
---

# Rangefinder Position Offset (RNGFND_POS)

## Description
`RNGFND_POS` (often appearing as `RNGFND1_POS_X/Y/Z`) tells the autopilot exactly where the sensor is mounted on the frame.

Correctly setting the Z-offset is particularly important for landing. If the sensor is mounted 10cm below the center of gravity but this is set to 0, the EKF will think the drone is 10cm higher than it actually is, potentially causing a hard landing.

*   **X:** Positive = Forward.
*   **Y:** Positive = Right.
*   **Z:** Positive = Down.

## Tuning & Behavior
*   **Default:** 0.
*   **Measurement:** Measure from the flight controller (center) to the face of the sensor.