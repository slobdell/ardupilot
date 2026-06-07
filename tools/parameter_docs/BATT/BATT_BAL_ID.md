---
layout: parameter
name: BATT_BAL_ID
display_name: Battery Balancer DroneCAN ID
description: The DroneCAN device ID associated with the battery balancing system.
default_value: 0
range: 0 127
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/batt_balance.cpp
---

# Battery Balancer DroneCAN ID (BATT_BAL_ID)

## Description
`BATT_BAL_ID` identifies the battery balancer unit on the DroneCAN bus.