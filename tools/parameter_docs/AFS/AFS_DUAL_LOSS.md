---
layout: parameter
name: AFS_DUAL_LOSS
display_name: Enable dual loss terminate
description: This enables the dual loss termination part of the AFS system. If this parameter is 1 and both GPS and the ground control station fail simultaneously, this will be considered a "dual loss" and cause termination.
default_value: 1
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Enable dual loss terminate (AFS_DUAL_LOSS)

## Description
Triggers termination if both GPS and GCS link are lost simultaneously.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Values:** 0:Disabled, 1:Enabled