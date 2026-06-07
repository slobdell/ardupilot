---
layout: parameter
name: FOLL_YAW_BEHAVE
display_name: Follow Yaw Behavior
description: Determines how the drone's heading (yaw) behaves when following a target.
default_value: 1
range: 0 3
units: 
group: FOLL
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L106
---

# Follow Yaw Behavior (FOLL_YAW_BEHAVE)

## Description
`FOLL_YAW_BEHAVE` defines what the drone points its "Face" (camera) at while it is chasing a target.

*   **0: None.** The drone keeps its current heading and does not automatically rotate.
*   **1: Face Target (Default).** The drone always turns to point its nose directly at the person or object it is following. Good for filming yourself.
*   **2: Face Next Waypoint.**
*   **3: Face Direction of Travel.** The drone points its nose where it is going, like a real airplane.