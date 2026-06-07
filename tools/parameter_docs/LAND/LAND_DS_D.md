---
layout: parameter
name: LAND_DS_D
display_name: Deepstall Steering D Gain
description: The derivative gain for the deepstall steering controller.
default_value: 0
range: 0 0.5
units: 
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L119
---

# Deepstall Steering D Gain (LAND_DS_D)

## Description
`LAND_DS_D` dampens the steering response to prevent oscillations.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Increase if you see rapid wobbling.