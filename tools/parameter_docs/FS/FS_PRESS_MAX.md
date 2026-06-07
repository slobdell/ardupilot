---
layout: parameter
name: FS_PRESS_MAX
display_name: Internal Pressure Failsafe
description: The maximum allowed internal pressure (in Pascals) for an ROV before a failsafe is triggered.
default_value: 105000
range: 0 200000
units: Pa
group: FS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L115
---

# Internal Pressure Failsafe (FS_PRESS_MAX)

## Description
`FS_PRESS_MAX` is a specialized safety setting for **ArduSub** ROVs.

It monitors the pressure sensor inside the ROV's dry housing. If the pressure rises above this limit, it usually indicates a leak or an impending structural failure. The autopilot can then trigger an emergency ascent or warning to protect the electronics.

## Tuning & Behavior
*   **Default:** 105,000 Pa (Standard atmospheric pressure is approx 101,325 Pa).
*   **Calibration:** Set this slightly above your normal sealed housing pressure.