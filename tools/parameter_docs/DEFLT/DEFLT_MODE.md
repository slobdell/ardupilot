---
layout: parameter
name: DEFLT_MODE
display_name: Mount Default Mode
description: Default mode for the mount at startup.
default_value: 3
range: 
units: 
group: DEFLT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp
---

# Mount Default Mode (DEFLT_MODE)

## Description
Specifies the initial operating state of the gimbal (mount) when the flight controller powers up.

## Tuning & Behavior
*   **Default Value:** 3 (RC Targeting)
*   **Values:** 0:Retracted, 1:Neutral, 2:MavLink Targeting, 3:RC Targeting, 4:GPS Point