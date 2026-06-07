---
layout: parameter
name: MNT1_ROLL_MAX
display_name: Mount Roll Maximum (Instance 1)
description: The maximum allowed roll angle (in degrees) for the gimbal.
default_value: 30
range: -180 180
units: deg
group: MNT
visual_asset_id: mnt_limits_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L50
---

# Mount Roll Maximum (MNT1_ROLL_MAX)

## Description
`MNT1_ROLL_MAX` sets the upper boundary for the gimbal's roll axis. 

This is used to prevent the gimbal from hitting its physical stops when the drone is banking hard. It is particularly important for 2-axis gimbals or 3-axis gimbals with limited roll travel.

*   **Units:** Degrees.
*   **Default:** 30.

## Tuning & Behavior
*   **Default:** 30.
*   **Constraint:** This value should match the physical limit of your gimbal. If the gimbal starts "stuttering" or making a high-pitched noise during a hard turn, your roll limits are likely too wide.