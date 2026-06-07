---
alias_target: CAN_D1_UC_ESC_RV
default_value: 0
description: Bitmask with one set for each output channel that uses a reversible ESC
  over DroneCAN. Reversible ESCs use both positive and negative values in RawCommands,
  with positive commanding the forward direction and negative commanding the reverse
  direction.
display_name: Bitmask for output channels for reversible ESCs over DroneCAN.
group: CAN
investigation_status: alias
layout: parameter
name: CAN_D2_UC_ESC_RV
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L162
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.h#L239
units: null
visual_asset_id: null
---

# Bitmask for output channels for reversible ESCs over DroneCAN.

**Note:** This parameter functions identically to [CAN_D1_UC_ESC_RV](../CAN/CAN_D1_UC_ESC_RV.html).
