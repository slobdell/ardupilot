---
layout: parameter
name: MNT1_YAW_MAX
display_name: Mount Yaw Maximum (Instance 1)
description: The maximum allowed yaw (pan) angle (in degrees) for the gimbal.
default_value: 180
range: -180 180
units: deg
group: MNT
visual_asset_id: mnt_limits_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L86
---

# Mount Yaw Maximum (MNT1_YAW_MAX)

## Description
`MNT1_YAW_MAX` defines how far the gimbal is allowed to rotate (pan) to the right.

*   **For 360-degree Gimbals:** Set to 180 (allowing full rotation).
*   **For Limited-travel Gimbals:** Set to the physical stop (e.g. 45 or 90 degrees).

## Tuning & Behavior
*   **Default:** 180.
*   **Cable Safety:** Ensure that your camera cables can handle the rotation set here without being pulled out or tangled.