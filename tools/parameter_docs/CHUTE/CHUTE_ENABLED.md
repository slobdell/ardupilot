---
layout: parameter
name: CHUTE_ENABLED
display_name: Parachute release enabled or disabled
description: Enables or disables the parachute release system.
default_value: 0
range: 0 1
units: 
group: CHUTE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Parachute/AP_Parachute.cpp
---

# Parachute release enabled or disabled (CHUTE_ENABLED)

## Description
Master switch for the emergency parachute system.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Values:** 0:Disabled, 1:Enabled
*   **When enabled, the autopilot will monitor for crash conditions and can trigger the parachute automatically or manually.**