---
layout: parameter
name: ARMING_ACCTHRESH
display_name: Accelerometer error threshold
description: Accelerometer error threshold used to determine inconsistent accelerometers. Compares this error range to other accelerometers to detect a hardware or calibration error. Lower value means tighter check and harder to pass arming check.
default_value: 0.75
range: 0.25 3.0
units: m/s/s
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Arming/AP_Arming.cpp
---

# Accelerometer error threshold (ARMING_ACCTHRESH)

## Description
Defines the maximum allowable difference between multiple accelerometers. If the readings diverge by more than this value, the aircraft will refuse to arm, indicating a potential sensor failure or calibration mismatch.

## Tuning & Behavior
*   **Default Value:** 0.75 m/s/s
*   **Range:** 0.25 to 3.0 m/s/s
*   **A lower value makes the pre-arm check more strict.**
*   **A higher value allows for more sensor noise/inconsistency but increases risk.**
