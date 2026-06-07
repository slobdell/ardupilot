---
layout: parameter
name: SERVO_BLH_POLES
display_name: BLHeli Motor Poles
description: The number of magnetic poles in the motor, used to calculate true RPM from BLHeli telemetry.
default_value: 14
range: 2 100
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Motor Poles (SERVO_BLH_POLES)

## Description
`SERVO_BLH_POLES` ensures the RPM displayed on your OSD is correct.

ESCs report "Electrical RPM" (how fast the field spins). To get "Mechanical RPM" (how fast the bell spins), you must divide by half the number of magnetic poles.

## Tuning & Behavior
*   **Default Value:** 14 (Standard for 22xx/23xx motors).
*   **Procedure:** Count the magnets on the bell of your motor. Enter that number here.