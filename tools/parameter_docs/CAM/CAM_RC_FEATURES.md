---
layout: parameter
name: CAM_RC_FEATURES
display_name: RunCam Feature Bitmask
description: Enables or disables specific serial control features for RunCam cameras.
default_value: 0
range: 0 15
units: 
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_RunCam.cpp#L120
---

# RunCam Feature Bitmask (CAM_RC_FEATURES)

## Description
`CAM_RC_FEATURES` allows you to customize what ArduPilot can do with your RunCam.

*   **Bit 0 (1):** Enable Start/Stop Recording.
*   **Bit 1 (2):** Enable OSD Menu control.
*   **Bit 2 (4):** Enable Camera Power Control (if supported by hardware).