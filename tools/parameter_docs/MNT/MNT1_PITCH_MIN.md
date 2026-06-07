---
layout: parameter
name: MNT1_PITCH_MIN
display_name: Mount Pitch Minimum (Instance 1)
description: The minimum downward tilt angle (in degrees) for the gimbal.
default_value: -90
range: -90 90
units: deg
group: MNT
visual_asset_id: mnt_limits_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L59
---

# Mount Pitch Minimum (MNT1_PITCH_MIN)

## Description
`MNT1_PITCH_MIN` defines the lower mechanical limit of your gimbal. 

*   **-90: Straight Down.** (Standard for mapping and FPV photography).
*   **0: Horizon.** (Prevents the gimbal from looking down at the ground).

## Tuning & Behavior
*   **Default:** -90.
*   **Action:** Ensure your gimbal can physically reach the value set here without straining the motors.