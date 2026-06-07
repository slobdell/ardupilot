---
layout: parameter
name: H_SV_MAN
display_name: Manual Servo Mode
description: Manual servo override for swash set-up. Must be 0 (Disabled) for flight!
default_value: 0
range: 0 4
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli.cpp
---

# Manual Servo Mode (H_SV_MAN)

## Description
A setup tool that forces the swashplate servos into specific positions (Max, Min, or Passthrough) to assist in mechanical leveling and linkage adjustment.
*   **WARNING: Must be set to 0 (Disabled) before attempting flight.**