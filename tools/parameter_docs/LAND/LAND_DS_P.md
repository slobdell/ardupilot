---
layout: parameter
name: LAND_DS_P
display_name: Deepstall Steering P Gain
description: The proportional gain for the deepstall steering controller.
default_value: 0
range: 0 5
units: 
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L119
---

# Deepstall Steering P Gain (LAND_DS_P)

## Description
`LAND_DS_P` controls how aggressively the plane tries to steer towards the landing point while falling.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Tune carefully. Too high, and the plane will rock violently. Too low, and it drifts with the wind.