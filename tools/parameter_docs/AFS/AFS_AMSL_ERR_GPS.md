---
layout: parameter
name: AFS_AMSL_ERR_GPS
display_name: Error margin for GPS based AMSL limit
description: This sets margin for error in GPS derived altitude limit. This error margin is only used if the barometer has failed. If the barometer fails then the GPS will be used to enforce the AMSL_LIMIT, but this margin will be subtracted from the AMSL_LIMIT first, to ensure that even with the given amount of GPS altitude error the pressure altitude is not breached. OBC users should set this to comply with their D2 safety case. A value of -1 will mean that barometer failure will lead to immediate termination.
default_value: -1
range: 
units: m
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Error margin for GPS based AMSL limit (AFS_AMSL_ERR_GPS)

## Description
Safety margin for GPS-based altitude limiting when the barometer fails.

## Tuning & Behavior
*   **Default Value:** -1 m
*   **-1 means barometer failure leads to immediate termination.**