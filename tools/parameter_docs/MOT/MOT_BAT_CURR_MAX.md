---
layout: parameter
name: MOT_BAT_CURR_MAX
display_name: Motor Current Max
description: The maximum total current (in Amps) the motors are allowed to draw.
default_value: 0
range: 0 200
units: A
group: MOT
visual_asset_id: batt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L80
---

# Motor Current Max (MOT_BAT_CURR_MAX)

## Description
`MOT_BAT_CURR_MAX` is a safety limiter for your battery and PDB.

If the total current drawn by the motors exceeds this value, ArduPilot will actively reduce the maximum throttle to bring the current back down.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **80% of your battery's C-Rating** or your PDB's max current.
*   **Safety:** This response is not instant (filtered by `MOT_BAT_CURR_TC`), so it won't stop a millisecond spike, but it will prevent sustained over-current.