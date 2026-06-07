---
layout: parameter
name: SERVO_BLH_PORT
display_name: BLHeli Serial Port
description: The serial port index used for BLHeli 4-way interface passthrough.
default_value: 0
range: 0 10
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Serial Port (SERVO_BLH_PORT)

## Description
`SERVO_BLH_PORT` is for legacy BLHeli setups.

Modern BLHeli_32/S ESCs use the DShot signal wire for passthrough. However, if you are using an older serial-based ESC programmer connected to a UART, this parameter selects which serial port it is plugged into.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled/USB).