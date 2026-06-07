---
layout: parameter
name: AFS_MAN_PIN
display_name: Manual Pin
description: This sets a digital output pin to set high when in manual mode. See the Wiki's "GPIOs" page for how to determine the pin number for a given autopilot.
default_value: -1
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Manual Pin (AFS_MAN_PIN)

## Description
Digital output pin indicating Manual mode.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled)
