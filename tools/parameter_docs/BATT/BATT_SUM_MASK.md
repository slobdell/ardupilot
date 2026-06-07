---
layout: parameter
name: BATT_SUM_MASK
display_name: Battery Sum Mask
description: Bitmask of battery monitor instances to sum together for this monitor.
default_value: 0
range: 
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Sum.cpp
---

# Battery Sum Mask (BATT_SUM_MASK)

## Description
Defines which battery monitor instances should be mathematically combined (summed) to create a single virtual battery monitor. This is useful for vehicles with multiple independent batteries powering the same rail.
