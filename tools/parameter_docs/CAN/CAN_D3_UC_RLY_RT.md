---
alias_target: CAN_D1_UC_RLY_RT
default_value: 0
description: Maximum transmit rate for relay outputs, note that this rate is per message
  each message does 1 relay, so if with more relays will take longer to update at
  the same rate, a extra message will be sent when a relay changes state
display_name: DroneCAN relay output rate
group: CAN
investigation_status: alias
layout: parameter
name: CAN_D3_UC_RLY_RT
range: 0 200
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L171
units: Hz
visual_asset_id: null
---

# DroneCAN relay output rate

**Note:** This parameter functions identically to [CAN_D1_UC_RLY_RT](../CAN/CAN_D1_UC_RLY_RT.html).
