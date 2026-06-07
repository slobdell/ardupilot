---
layout: parameter
name: SERVO_SBUS_RATE
display_name: SBUS Output Rate
description: The update rate (in Hz) for the SBUS output port.
default_value: 50
range: 50 333
units: Hz
group: SERVO
visual_asset_id: sbus_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SRV_Channel/SRV_Channel.cpp#L100
---

# SBUS Output Rate (SERVO_SBUS_RATE)

## Description
`SERVO_SBUS_RATE` controls the speed of the SBUS output stream (if enabled via `BRD_SBUS_OUT`).

Standard SBUS is 50Hz (analog servo compatible). High-speed SBUS is often 200Hz or 333Hz.

## Tuning & Behavior
*   **Default Value:** 50 Hz.
*   **Recommendation:** Ensure your servos can handle high frame rates before increasing this.