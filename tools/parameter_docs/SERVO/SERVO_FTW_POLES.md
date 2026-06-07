---
layout: parameter
name: SERVO_FTW_POLES
display_name: FETtec OneWire Motor Poles
description: The number of magnetic poles in the motors, used to calculate correct RPM from the OneWire telemetry.
default_value: 14
range: 2 48
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_FETtecOneWire/AP_FETtecOneWire.cpp#L102
---

# FETtec OneWire Motor Poles (SERVO_FTW_POLES)

## Description
`SERVO_FTW_POLES` ensures your RPM readings are accurate.

ESCs measure "Electrical RPM." To convert this to real "Mechanical RPM," ArduPilot needs to know how many magnets (poles) are inside the motor.

## Tuning & Behavior
*   **Default Value:** 14.
*   **Common Values:** 14 for standard 2207/2306 drone motors. 28+ for larger industrial motors.