---
layout: parameter
name: AROT_ENABLE
display_name: Enable autonomous autorotation
description: Allows you to enable (1) or disable (0) the autonomous autorotation capability.
default_value: 0
range: 0 1
units: 
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Enable autonomous autorotation (AROT_ENABLE)

## Description
Enables the autonomous autorotation feature for helicopters, allowing the flight controller to manage head speed and glide profile during an engine failure or manual entry.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Values:** 0:Disabled, 1:Enabled
*   **Requires careful tuning of head speed and collective parameters for safe operation.**