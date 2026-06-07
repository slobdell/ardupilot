---
layout: parameter
name: AFS_TERM_PIN
display_name: Terminate Pin
description: This sets a digital output pin to set high on flight termination. Some common values are given, but see the Wiki's "GPIOs" page for how to determine the pin number for a given autopilot.
default_value: -1
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Terminate Pin (AFS_TERM_PIN)

## Description
Digital output pin triggered high when the flight is terminated.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled)
*   **Values:** -1:Disabled, 49:BB Blue GP0 pin 4, 50:AUXOUT1, 51:AUXOUT2, 52:AUXOUT3, 53:AUXOUT4, 54:AUXOUT5, 55:AUXOUT6, 57:BB Blue GP0 pin 3, 113:BB Blue GP0 pin 6, 116:BB Blue GP0 pin 5
