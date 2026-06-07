---
layout: parameter
name: LAND_DS_ELEV_PWM
display_name: Deepstall Elevator PWM
description: The absolute PWM value (in microseconds) sent to the elevator servo to force the deep stall.
default_value: 1500
range: 900 2100
units: PWM
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L76
---

# Deepstall Elevator PWM (LAND_DS_ELEV_PWM)

## Description
`LAND_DS_ELEV_PWM` is the "Stall Position."

This is the exact servo signal sent to the elevator to hold the nose up (or down, for inverted deep stall).

## Tuning & Behavior
*   **Default Value:** 1500 (Neutral).
*   **Recommendation:** Set to your maximum up-elevator PWM (e.g., 1900 or 1100 depending on reversal). Ensure it is enough to keep the wing fully stalled.
