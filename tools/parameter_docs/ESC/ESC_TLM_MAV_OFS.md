---
layout: parameter
name: ESC_TLM_MAV_OFS
display_name: ESC Telemetry mavlink offset
description: Offset to apply to ESC numbers when reporting as ESC_TELEMETRY packets over MAVLink.
default_value: 0
range: 0 31
units: 
group: ESC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ESC_Telem/AP_ESC_Telem.cpp
---

# ESC Telemetry mavlink offset (ESC_TLM_MAV_OFS)

## Description
Remaps the ESC instance IDs for MAVLink reporting. This allows, for example, motors 5-8 to be displayed as ESCs 1-4 on a ground station for easier monitoring.
*   **A value of 4 shifts everything down by 4.**