---
layout: parameter
name: AFS_ENABLE
display_name: Enable Advanced Failsafe
description: This enables the advanced failsafe system. If this is set to zero (disable) then all the other AFS options have no effect.
default_value: 0
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Enable Advanced Failsafe (AFS_ENABLE)

## Description
Enables the advanced failsafe system.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Values:** 0:Disabled, 1:Enabled