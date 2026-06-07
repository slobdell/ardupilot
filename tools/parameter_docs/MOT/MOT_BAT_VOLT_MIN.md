---
layout: parameter
name: MOT_BAT_VOLT_MIN
display_name: Battery voltage compensation minimum voltage
description: The battery voltage at which maximum boost is applied to throttle to compensate for sag.
default_value: 0
range: 6 42
units: V
group: MOT
visual_asset_id: mot_bat_volt_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L72
---

# Battery voltage compensation minimum voltage (MOT_BAT_VOLT_MIN)

## Description
`MOT_BAT_VOLT_MIN` is the "Empty" reference for thrust scaling.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **3.3V * Cell Count**.
    *   **4S:** 13.2V
    *   **6S:** 19.8V