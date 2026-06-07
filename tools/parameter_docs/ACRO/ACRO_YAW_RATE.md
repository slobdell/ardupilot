---
layout: parameter
name: ACRO_YAW_RATE
display_name: ACRO mode yaw rate
description: The maximum yaw rate at full stick deflection in ACRO mode (ArduPlane).
default_value: 0
range: 0 500
units: deg/s
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# ACRO mode yaw rate (ACRO_YAW_RATE)

## Description
Maximum angular velocity for yaw in Plane ACRO mode.

## Tuning & Behavior
*   **Default Value:** 0 (Rudder directly controlled by stick)
*   **Range:** 0 to 500 deg/s
*   **Requires YAW_RATE_ENABLE = 1 to take effect.**
