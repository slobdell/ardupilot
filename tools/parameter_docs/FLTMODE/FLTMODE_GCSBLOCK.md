---
layout: parameter
name: FLTMODE_GCSBLOCK
display_name: Flight mode GCS block
description: Bitmask of flight modes to block from being set via GCS.
default_value: 0
range: 
units: 
group: FLTMODE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Vehicle/AP_Vehicle.cpp
---

# Flight mode GCS block (FLTMODE_GCSBLOCK)

## Description
A safety feature that prevents specific flight modes from being engaged via a ground station command. This ensures that certain critical modes can only be entered using the physical RC transmitter sticks.