---
layout: parameter
name: DSHOT_ESC
display_name: Servo DShot ESC type
description: DShot ESC type for all outputs. The ESC type affects the range of DShot commands available and the bit widths used.
default_value: 0
range: 0 4
units: 
group: DSHOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channels.cpp
---

# Servo DShot ESC type (DSHOT_ESC)

## Description
Specifies the firmware generation of the connected DShot ESCs, which determines the availability of features like bi-directional telemetry.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Values:** 0:None, 1:BLHeli32/Kiss/AM32, 2:BLHeli_S/BlueJay, 3:BLHeli32/AM32/Kiss+EDT, 4:BLHeli_S/BlueJay+EDT