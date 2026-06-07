---
layout: parameter
name: LAND_DS_I
display_name: Deepstall Steering I Gain
description: The integral gain for the deepstall steering controller.
default_value: 0
range: 0 5
units: 
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L119
---

# Deepstall Steering I Gain (LAND_DS_I)

## Description
`LAND_DS_I` corrects for wind drift during the descent.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use sparingly to correct steady-state heading errors.