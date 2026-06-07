---
layout: parameter
name: AFS_MAX_RANGE
display_name: Max allowed range
description: This is the maximum range of the vehicle in kilometers from first arming. If the vehicle goes beyond this range then the TERM_ACTION is performed. A value of zero disables this feature.
default_value: 0
range: 
units: km
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Max allowed range (AFS_MAX_RANGE)

## Description
Distance limit from the arming point, triggering termination if exceeded.

## Tuning & Behavior
*   **Default Value:** 0 km (Disabled)
*   **Units are in kilometers.**
