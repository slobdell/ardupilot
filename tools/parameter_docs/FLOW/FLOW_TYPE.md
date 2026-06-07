---
layout: parameter
name: FLOW_TYPE
display_name: Optical flow sensor type
description: Optical flow sensor type.
default_value: 0
range: 
units: 
group: FLOW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpticalFlow/AP_OpticalFlow.cpp
---

# Optical flow sensor type (FLOW_TYPE)

## Description
Optical flow sensor type.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Values:** 0:None, 1:PX4Flow, 2:Pixart, 3:Bebop, 4:CXOF, 5:MAVLink, 6:DroneCAN, 7:MSP, 8:UPFLOW