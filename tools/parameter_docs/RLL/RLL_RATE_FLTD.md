---
layout: parameter
name: RLL_RATE_FLTD
display_name: Roll Rate Derivative Filter
description: The cutoff frequency (in Hz) for the D-term filter. Essential for preventing noise amplification.
default_value: 0
range: 0 50
units: Hz
group: RLL
visual_asset_id: filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Rate Derivative Filter (RLL_RATE_FLTD)

## Description
`RLL_RATE_FLTD` cleans up the gyro signal before the D-term calculates the rate of change.

The Derivative term amplifies noise. Without this filter, engine vibrations would cause the D-term to command erratic servo movements, leading to "Jitter" and hot servos.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Always set this if using D-gain.
    *   **Large Plane:** 5 - 10 Hz.
    *   **Small Plane:** 10 - 20 Hz.