---
layout: parameter
name: CUST_ROT1_ROLL
display_name: Custom Rotation 1 - Roll
description: Roll component of the first custom rotation.
default_value: 0
range: -180 180
units: deg
group: CUST
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CustomRotations/AP_CustomRotations_params.cpp
---

# Custom Rotation 1 - Roll (CUST_ROT1_ROLL)

## Description
Defines the roll angle for the first custom software rotation. 
*   **Ordering: Euler 321 (Yaw, then Pitch, then Roll).**