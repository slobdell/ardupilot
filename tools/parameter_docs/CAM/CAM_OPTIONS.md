---
layout: parameter
name: CAM_OPTIONS
display_name: Camera options
description: Camera options bitmask.
default_value: 0
range: 
units: 
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp
---

# Camera options (CAM_OPTIONS)

## Description
Configuration bitmask for various camera behaviors.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: Recording Starts at arming and stops at disarming