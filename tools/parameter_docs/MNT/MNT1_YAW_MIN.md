---
layout: parameter
name: MNT1_YAW_MIN
display_name: Mount Yaw Minimum (Instance 1)
description: The minimum allowed yaw (pan) angle (in degrees) for the gimbal.
default_value: -180
range: -180 180
units: deg
group: MNT
visual_asset_id: mnt_limits_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L77
---

# Mount Yaw Minimum (MNT1_YAW_MIN)

## Description
`MNT1_YAW_MIN` defines how far the gimbal is allowed to rotate (pan) to the left. 

This is the negative counterpart to [MNT1_YAW_MAX](MNT1_YAW_MAX.html). 

*   **Units:** Degrees.
*   **Default:** -180 (Full left rotation).

## Tuning & Behavior
*   **Default:** -180.
*   **Alignment:** Ensure that 0 degrees corresponds to the camera pointing directly forward along the vehicle's centerline.