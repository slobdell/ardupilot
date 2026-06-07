---
layout: parameter
name: AFS_OPTIONS
display_name: AFS options
description: Configuration options for Advanced Failsafe behavior.
default_value: 0
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# AFS options (AFS_OPTIONS)

## Description
Bitmask for configuring specific Advanced Failsafe behaviors.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:** 
    *   0: Continue the mission even after comms are recovered (does not go to the mission item at the time comms were lost)
    *   1: Enable AFS for all autonomous modes (not just AUTO)
Internal logic check: bit 0 skips returning to the exact WP where comms were lost; bit 1 extends protection beyond just the AUTO mission mode.