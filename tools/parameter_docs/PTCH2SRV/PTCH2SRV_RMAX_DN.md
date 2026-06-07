---
layout: parameter
name: PTCH2SRV_RMAX_DN
display_name: Pitch Max Rate Down
description: The maximum allowed pitch-down rate (in deg/s).
default_value: 0
range: 0 180
units: deg/s
group: PTCH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_PitchController.cpp#L52
---

# Pitch Max Rate Down (PTCH2SRV_RMAX_DN)

## Description
`PTCH2SRV_RMAX_DN` limits how fast the autopilot is allowed to push the nose down. 

This is used to prevent aggressive "nose dives" that could lead to over-speed conditions or excessive negative G-loads.