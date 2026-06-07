---
layout: parameter
name: CAM_TYPE
display_name: Camera shutter (trigger) type
description: Specifies how the camera is triggered to take a picture.
default_value: 0
range: 
units: 
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera shutter (trigger) type (CAM_TYPE)

## Description
Defines the communication method used to trigger the camera.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Values:** 0:None, 1:Servo, 2:Relay, 3:GoPro (Solo), 4:Mount (Siyi/Topotek/Viewpro/Xacti), 5:MAVLink, 6:MAVLinkCamV2, 7:Scripting