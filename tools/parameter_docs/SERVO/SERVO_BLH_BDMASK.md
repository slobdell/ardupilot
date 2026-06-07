---
layout: parameter
name: SERVO_BLH_BDMASK
display_name: BLHeli Bidirectional Mask
description: A bitmask of channels to enable Bidirectional DShot (RPM telemetry over signal wire).
default_value: 0
range: 0 4294967295
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Bidirectional Mask (SERVO_BLH_BDMASK)

## Description
`SERVO_BLH_BDMASK` enables high-speed RPM feedback over the existing motor signal wires.

This is required for the "Harmonic Notch Filter" to track motor speed perfectly. Unlike standard telemetry, this updates thousands of times per second.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Enable for all motors if your ESCs support BLHeli_32 or Bluejay.