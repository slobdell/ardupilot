---
layout: parameter
name: BRD_SAFETYOPTION
display_name: Options for safety button behavior
description: Controls the activation and behavior of the physical safety button.
default_value: 3
range: 
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Options for safety button behavior (BRD_SAFETYOPTION)

## Description
Configures the specific interaction rules for the hardware safety button, such as whether it can be used to re-engage safety while armed.

## Tuning & Behavior
*   **Default Value:** 3 (Button active for Safety On/Off)
*   **Bitmask:**
    *   0: ActiveForSafetyDisable
    *   1: ActiveForSafetyEnable
    *   2: ActiveWhenArmed
    *   3: Force safety on when the aircraft disarms