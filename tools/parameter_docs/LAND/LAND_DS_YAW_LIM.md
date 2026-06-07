---
layout: parameter
name: LAND_DS_YAW_LIM
display_name: Deepstall Yaw Rate Limit
description: The maximum yaw rate (in degrees per second) allowed during a deepstall landing.
default_value: 10
range: 0 90
units: deg/s
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L99
---

# Deepstall Yaw Rate Limit (LAND_DS_YAW_LIM)

## Description
`LAND_DS_YAW_LIM` prevents the plane from spinning like a top while falling.

In a deepstall, the rudder is often less effective or can cause roll coupling. This parameter limits how hard the L1 controller tries to steer the heading.

## Tuning & Behavior
*   **Default Value:** 10 deg/s.