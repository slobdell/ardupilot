---
layout: parameter
name: SERVO1_TRIM
display_name: Servo 1 Trim
description: The neutral (center) PWM value for Output 1.
default_value: 1500
range: 800 2200
units: PWM
group: SERVO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channel.cpp#L55
---

# Servo 1 Trim (SERVO1_TRIM)

## Description
`SERVO1_TRIM` defines the "Center" position of a servo or motor. 

When the autopilot is not demanding any movement (e.g., sticks are centered in Stabilize mode), it sends this PWM value to the output.

*   **Standard Setting:** 1500 (µs).
*   **Usage:** Use this to mechanically center a servo arm if it's slightly off-center, or to set the zero-thrust point for ESCs that support reverse thrust.

## Tuning & Behavior
*   **Calibration:** Most Ground Control Stations have a "Radio Calibration" or "Servo Output" screen where you can adjust this value to level your control surfaces.
*   **Safety:** Do not use large trim offsets to fix a crooked mechanical linkage. It is always better to adjust the linkage physically so that the trim remains near 1500.