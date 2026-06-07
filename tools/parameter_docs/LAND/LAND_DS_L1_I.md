---
layout: parameter
name: LAND_DS_L1_I
display_name: Deepstall L1 Integrator Gain
description: The integrator gain for the L1 navigation controller to correct for cross-track error.
default_value: 0
range: 0 1
units: 
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L104
---

# Deepstall L1 Integrator Gain (LAND_DS_L1_I)

## Description
`LAND_DS_L1_I` helps the plane stay on the line in a crosswind.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Increase if the plane consistently lands downwind of the target point.