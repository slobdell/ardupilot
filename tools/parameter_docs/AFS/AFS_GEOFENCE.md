---
layout: parameter
name: AFS_GEOFENCE
display_name: Enable geofence Advanced Failsafe
description: This enables the geofence part of the AFS. Will only be in effect if AFS_ENABLE is also 1.
default_value: 1
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Enable geofence Advanced Failsafe (AFS_GEOFENCE)

## Description
Enables geofence-triggered failsafes within the AFS system.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Requires AFS_ENABLE = 1 to function.**
