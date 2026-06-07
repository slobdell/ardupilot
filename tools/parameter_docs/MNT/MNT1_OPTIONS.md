---
layout: parameter
name: MNT1_OPTIONS
display_name: Mount Options (Instance 1)
description: Bitmask of advanced features for the gimbal controller.
default_value: 0
range: 0 1
units: 
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L174
---

# Mount Options (MNT1_OPTIONS)

## Description
`MNT1_OPTIONS` is a bitmask to enable specific Gimbal behaviors.

*   **Bit 0 (1): Lock state from previous mode.** If you manually lock the gimbal's heading (using an RC switch) and then change the flight mode, the gimbal will stay locked in its current position rather than snapping back to its default orientation.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Enable Bit 0 if you are performing cinematic shots where you want the camera to stay pointed at a subject even if the drone's autopilot behavior changes.