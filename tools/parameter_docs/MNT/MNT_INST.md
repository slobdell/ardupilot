---
layout: parameter
title: MNT_INST
name: Camera Mount instance
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Camera/AP_Camera_Params.cpp#L88
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Camera/AP_Camera_Params.h#L25
---

# MNT_INST: Camera Mount instance

## Description
Mount instance camera is associated with. 0 means camera and mount have identical instance numbers (e.g., Camera 1 -> Mount 1).

## Values
- **Range:** 0 to 2
- **Default:** 0

## Description
This parameter links a configured Camera (`CAM` or `CAM2`) to a specific Gimbal/Mount (`MNT` or `MNT2`).

- **0:** Default mapping (Camera 1 uses Mount 1, Camera 2 uses Mount 2).
- **1:** This Camera uses Mount 1.
- **2:** This Camera uses Mount 2.

## Source Code
[ardupilot/libraries/AP_Camera/AP_Camera_Params.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Camera/AP_Camera_Params.cpp#L88)

