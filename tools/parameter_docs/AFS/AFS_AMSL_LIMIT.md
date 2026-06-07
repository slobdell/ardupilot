---
layout: parameter
name: AFS_AMSL_LIMIT
display_name: AMSL limit
description: This sets the AMSL (above mean sea level) altitude limit. If the pressure altitude determined by QNH exceeds this limit then flight termination will be forced. Note that this limit is in meters, whereas pressure altitude limits are often quoted in feet. A value of zero disables the pressure altitude limit.
default_value: 0
range: 
units: m
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# AMSL limit (AFS_AMSL_LIMIT)

## Description
Maximum altitude (Above Mean Sea Level) allowed before forced termination.

## Tuning & Behavior
*   **Default Value:** 0 m (Disabled)
*   **Units are in meters.**
