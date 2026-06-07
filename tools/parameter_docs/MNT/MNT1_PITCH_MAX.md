---
layout: parameter
name: MNT1_PITCH_MAX
display_name: Mount Pitch Maximum (Instance 1)
description: The maximum upward tilt angle (in degrees) for the gimbal.
default_value: 20
range: -90 90
units: deg
group: MNT
visual_asset_id: mnt_limits_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L68
---

# Mount Pitch Maximum (MNT1_PITCH_MAX)

## Description
`MNT1_PITCH_MAX` defines the upper mechanical limit of your gimbal. 

Setting this correctly prevents the gimbal from trying to tilt past its physical stop, which can cause motor overheating, "gimbal flip," or mechanical damage. 

*   **Default:** 20 degrees (pointing slightly above the horizon).
*   **Recommendation:** Match this to your gimbal's physical capability.

## Tuning & Behavior
*   **Default:** 20.
*   **Constraint:** This value must be greater than [MNT1_PITCH_MIN](MNT1_PITCH_MIN.html).
*   **Usage:** For mapping missions (straight down), you might set this to 0 to keep the camera strictly at or below the horizon.