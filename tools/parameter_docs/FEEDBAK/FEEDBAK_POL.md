---
layout: parameter
name: FEEDBAK_POL
display_name: Camera feedback pin polarity
description: Polarity for feedback pin. 1:TriggerHigh, 0:TriggerLow.
default_value: 1
range: 0 1
units: 
group: FEEDBAK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera feedback pin polarity (FEEDBAK_POL)

## Description
Defines whether the feedback signal from the camera is active-high or active-low.