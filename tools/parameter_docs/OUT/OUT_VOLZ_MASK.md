---
layout: parameter
name: OUT_VOLZ_MASK
display_name: Volz Servo Mask (Alias)
description: Bitmask of output channels using the Volz serial protocol.
default_value: 0
range: 0 4294967295
units: 
group: OUT
visual_asset_id: servo_volz_diagram
investigation_status: alias
alias_target: SERVO_VOLZ_MASK
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Volz_Protocol/AP_Volz_Protocol.cpp#L36
---

# Volz Servo Mask (OUT_VOLZ_MASK)

**Note:** This parameter is an alias for [SERVO_VOLZ_MASK](../SERVO/SERVO_VOLZ_MASK.html).