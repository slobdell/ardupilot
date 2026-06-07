---
alias_target: CAN_D1_PC_ECU_ID
default_value: PICCOLO_CAN_ECU_ID_DEFAULT
description: Node ID to send ECU throttle messages to. Set to zero to disable ECU
  throttle messages. Set to 255 to broadcast to all ECUs.
display_name: ECU Node ID
group: CAN
investigation_status: alias
layout: parameter
name: CAN_D2_PC_ECU_ID
range: 0 255
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_PiccoloCAN/AP_PiccoloCAN.cpp#L95
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_PiccoloCAN/AP_PiccoloCAN.h#L131
units: null
visual_asset_id: null
---

# ECU Node ID

**Note:** This parameter functions identically to [CAN_D1_PC_ECU_ID](../CAN/CAN_D1_PC_ECU_ID.html).
