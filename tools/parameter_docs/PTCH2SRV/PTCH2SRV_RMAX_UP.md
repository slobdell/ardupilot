---
layout: parameter
name: PTCH2SRV_RMAX_UP
display_name: Pitch Max Rate Up
description: The maximum allowed pitch-up rate (in deg/s).
default_value: 0
range: 0 180
units: deg/s
group: PTCH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_PitchController.cpp#L44
---

# Pitch Max Rate Up (PTCH2SRV_RMAX_UP)

## Description
`PTCH2SRV_RMAX_UP` limits how fast the autopilot is allowed to pull the nose up. 

This is an important safety limit to prevent the drone from performing a maneuver so aggressive that it stalls or exceeds the structural limits of the airframe.

*   **0:** Disabled (No limit).
*   **Value:** Rate in degrees per second.