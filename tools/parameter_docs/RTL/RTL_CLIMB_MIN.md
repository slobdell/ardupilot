---
layout: parameter
name: RTL_CLIMB_MIN
display_name: RTL Minimum Climb
description: The vehicle will climb at least this many centimeters during the initial stage of RTL, even if it is already above RTL_ALT.
default_value: 0
range: 0 1000
units: cm
group: RTL
visual_asset_id: rtl_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L946
---

# RTL Minimum Climb (RTL_CLIMB_MIN)

## Description
`RTL_CLIMB_MIN` ensures the drone does *something* vertical when RTL is triggered.

If `RTL_ALT` is 15m and you are at 20m, the drone would normally just fly home. If you set `RTL_CLIMB_MIN` to 500 (5m), the drone will climb to 25m first. This is a visual cue to the pilot that RTL has engaged.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **0** unless you specifically want this "Jump" behavior.