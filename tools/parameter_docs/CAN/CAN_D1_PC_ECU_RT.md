---
layout: parameter
name: CAN_D1_PC_ECU_RT
display_name: PiccoloCAN ECU Output Rate (Driver 1)
description: The frequency (in Hz) at which ECU throttle command messages are transmitted over the PiccoloCAN bus.
default_value: 50
range: 1 500
units: Hz
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_PiccoloCAN/AP_PiccoloCAN.cpp#L44
---

# PiccoloCAN ECU Output Rate (CAN_D1_PC_ECU_RT)

## Description
`CAN_D1_PC_ECU_RT` sets the update frequency for an internal combustion engine's Electronic Control Unit (ECU) connected via PiccoloCAN.
