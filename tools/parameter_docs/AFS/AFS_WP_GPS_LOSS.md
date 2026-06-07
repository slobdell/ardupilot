---
layout: parameter
name: AFS_WP_GPS_LOSS
display_name: GPS Loss Waypoint
description: Waypoint number to navigate to on GPS lock loss.
default_value: 0
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# GPS Loss Waypoint (AFS_WP_GPS_LOSS)

## Description
Waypoint designated for navigation when GPS signal is lost.

## Tuning & Behavior
*   **Default Value:** 0 (None)
