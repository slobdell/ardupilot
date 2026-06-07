---
layout: parameter
name: MNT_RETRACT
display_name: Mount Retracted Position
description: The 3-axis position (Roll, Pitch, Yaw) the gimbal moves to when stowed.
default_value: 0
range: -180 180
units: deg
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L111
---

# Mount Retracted Position (MNT_RETRACT)

## Description
`MNT_RETRACT` defines the "Parked" position of the gimbal. 

This is used when the gimbal mode is set to **Retracted**. For many professional drones, this position points the camera inward or upward into a protective cavity to prevent the lens from being scratched or the motors from being strained during landing or transport.

## Tuning & Behavior
*   **Default:** 0 (Centered).
*   **Usage:** Set the Roll, Pitch, and Yaw values to match your gimbal's specific stowing requirement.
*   **Safety:** Ensure the retracted position does not cause the gimbal to hit the airframe or stretch internal cables.