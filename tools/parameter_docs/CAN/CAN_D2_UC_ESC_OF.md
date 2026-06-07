---
alias_target: CAN_D1_UC_ESC_OF
default_value: 0
description: Offset for ESC numbering in DroneCAN ESC RawCommand messages. This allows
  for more efficient packing of ESC command messages. If your ESCs are on servo functions
  5 to 8 and you set this parameter to 4 then the ESC RawCommand will be sent with
  the first 4 slots filled. This can be used for more efficient usage of CAN bandwidth
display_name: ESC Output channels offset
group: CAN
investigation_status: alias
layout: parameter
name: CAN_D2_UC_ESC_OF
range: 0 18
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L148
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.h#L234
units: null
visual_asset_id: null
---

# ESC Output channels offset

**Note:** This parameter functions identically to [CAN_D1_UC_ESC_OF](../CAN/CAN_D1_UC_ESC_OF.html).
