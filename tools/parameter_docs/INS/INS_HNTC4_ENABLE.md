---
layout: parameter
name: INS_HNTC4_ENABLE
display_name: Harmonic Notch Filter 4 Enable
description: Enables the fourth harmonic notch filter.
default_value: 0
range: 0 1
units: 
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_config.cpp#L100
---

# Harmonic Notch Filter 4 Enable (INS_HNTC4_ENABLE)

## Description
`INS_HNTC4_ENABLE` turns on an additional dynamic filter.

Most drones only need one or two notch filters. However, complex multi-rotor setups (like a dodecacopter) or frames with multiple vibration sources might need a fourth filter to clean up the gyro signal completely.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.