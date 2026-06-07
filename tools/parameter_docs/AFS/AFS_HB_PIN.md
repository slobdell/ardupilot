---
layout: parameter
name: AFS_HB_PIN
display_name: Heartbeat Pin
description: This sets a digital output pin which is cycled at 10Hz when termination is not activated. Note that if a FS_TERM_PIN is set then the heartbeat pin will continue to cycle at 10Hz when termination is activated, to allow the termination board to distinguish between autopilot crash and termination. Some common values are given, but see the Wiki's "GPIOs" page for how to determine the pin number for a given autopilot.
default_value: -1
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Heartbeat Pin (AFS_HB_PIN)

## Description
Digital output pin used for monitoring autopilot health via a 10Hz heartbeat.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled)
*   **Values:** -1:Disabled, 49:BB Blue GP0 pin 4, 50:AUXOUT1, 51:AUXOUT2, 52:AUXOUT3, 53:AUXOUT4, 54:AUXOUT5, 55:AUXOUT6, 57:BB Blue GP0 pin 3, 113:BB Blue GP0 pin 6, 116:BB Blue GP0 pin 5