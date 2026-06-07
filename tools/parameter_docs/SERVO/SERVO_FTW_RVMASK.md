---
layout: parameter
name: SERVO_FTW_RVMASK
display_name: FETtec OneWire Reverse Mask
description: A bitmask of motor channels whose rotation direction is reversed via the OneWire protocol.
default_value: 0
range: 0 65535
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_FETtecOneWire/AP_FETtecOneWire.cpp#L101
---

# FETtec OneWire Reverse Mask (SERVO_FTW_RVMASK)

## Description
`SERVO_FTW_RVMASK` allows you to reverse your motor directions in software.

Instead of swapping two wires on your motor, you can set a bit in this mask to tell the FETtec ESC to spin the motor in the opposite direction.