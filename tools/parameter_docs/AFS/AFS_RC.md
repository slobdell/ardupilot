---
layout: parameter
name: AFS_RC
display_name: Enable RC Advanced Failsafe
description: This enables the RC part of the AFS. Will only be in effect if AFS_ENABLE is also 1.
default_value: 1
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Enable RC Advanced Failsafe (AFS_RC)

## Description
Enables RC-link loss detection and associated actions within the AFS system.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Requires AFS_ENABLE = 1 to function.**
