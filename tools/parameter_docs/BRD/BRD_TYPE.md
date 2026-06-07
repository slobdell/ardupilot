---
layout: parameter
name: BRD_TYPE
display_name: Board type
description: This allows selection of a PX4 or VRBRAIN board type. If set to zero then the board type is auto-detected.
default_value: 0
range: 
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Board type (BRD_TYPE)

## Description
Specifies the hardware platform type. While ArduPilot usually auto-detects the board, this parameter can be used to force a specific driver set.

## Tuning & Behavior
*   **Default Value:** 0 (Auto-detect)
*   **Values:** 1:PX4V1, 2:Pixhawk, 3:Cube/Pixhawk2, 4:Pixracer, etc.
*   **Requires reboot to take effect.**
