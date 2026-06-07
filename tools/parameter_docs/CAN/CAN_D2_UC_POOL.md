---
alias_target: CAN_D1_UC_POOL
default_value: DRONECAN_NODE_POOL_SIZE
description: Amount of memory in bytes to allocate for the DroneCAN memory pool. More
  memory is needed for higher CAN bus loads
display_name: CAN pool size
group: CAN
investigation_status: alias
layout: parameter
name: CAN_D2_UC_POOL
range: 1024 16384
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L155
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.h#L238
units: null
visual_asset_id: null
---

# CAN pool size

**Note:** This parameter functions identically to [CAN_D1_UC_POOL](../CAN/CAN_D1_UC_POOL.html).
