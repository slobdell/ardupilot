---
layout: parameter
name: AFS_GCS_TIMEOUT
display_name: GCS timeout
description: The time (in seconds) of persistent data link loss before GCS failsafe occurs.
default_value: 10
range: 
units: s
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# GCS timeout (AFS_GCS_TIMEOUT)

## Description
Duration of GCS link loss before triggering failsafe.

## Tuning & Behavior
*   **Default Value:** 10 s