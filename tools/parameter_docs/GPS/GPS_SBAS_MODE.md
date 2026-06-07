---
layout: parameter
name: GPS_SBAS_MODE
display_name: SBAS Mode
description: Configures the Satellite Based Augmentation System (SBAS) mode.
default_value: 2
range: 0 2
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# SBAS Mode (GPS_SBAS_MODE)

## Description
Enables or disables the use of SBAS corrections (like WAAS or EGNOS) to improve GPS accuracy.
*   **0: Disabled**
*   **1: Enabled**
*   **2: No Change (Don't reconfigure the module)**
