---
layout: parameter
name: CAN_D1_PC_SRV_RT
display_name: PiccoloCAN Servo Output Rate (Driver 1)
description: The frequency (in Hz) at which servo command messages are transmitted over the PiccoloCAN bus.
default_value: 50
range: 1 500
units: Hz
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_PiccoloCAN/AP_PiccoloCAN.cpp#L42
---

# PiccoloCAN Servo Output Rate (CAN_D1_PC_SRV_RT)

## Description
`CAN_D1_PC_SRV_RT` defines the update frequency for control surfaces (ailerons, elevators) using PiccoloCAN servos.
