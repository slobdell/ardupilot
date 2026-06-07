---
layout: parameter
name: MNT1_ROLL_MIN
display_name: Mount Roll Minimum (Instance 1)
description: The minimum allowed roll angle (in degrees) for the gimbal.
default_value: -30
range: -180 180
units: deg
group: MNT
visual_asset_id: mnt_limits_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L41
---

# Mount Roll Minimum (MNT1_ROLL_MIN)

## Description
`MNT1_ROLL_MIN` sets the lower boundary for the gimbal's roll axis. 

This is the negative counterpart to [MNT1_ROLL_MAX](MNT1_ROLL_MAX.html). It ensures the gimbal doesn't try to bank too far in the opposite direction.

*   **Units:** Degrees.
*   **Default:** -30.

## Tuning & Behavior
*   **Default:** -30.
*   **Safety:** Always verify that your gimbal can physically reach these angles by manually banking the drone while it is powered on.