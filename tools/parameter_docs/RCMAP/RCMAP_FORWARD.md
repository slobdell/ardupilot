---
layout: parameter
name: RCMAP_FORWARD
display_name: Forward Channel Mapping
description: Selects the RC input channel used for forward/backward movement.
default_value: 0
range: 1 16
units: 
group: RCMAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RCMapper/AP_RCMapper.cpp#L52
---

# Forward Channel Mapping (RCMAP_FORWARD)

## Description
`RCMAP_FORWARD` allows you to customize which stick or switch on your transmitter controls the vehicle's forward/reverse movement. 

This is primarily used for **6-DOF multicopters** (omnicopters) and **Sub/ROV** applications where the standard 4-axis control (Roll, Pitch, Throttle, Yaw) is expanded to include direct translation. 

## Tuning & Behavior
*   **Default:** 0 (Disabled/Unmapped).
*   **Usage:** Set to the channel number (e.g. 6) that your transmitter is sending the forward-translation signal on.
*   **Reboot Required:** Yes.