---
layout: parameter
name: AFS_TERMINATE
display_name: Force Terminate
description: Can be set in flight to force termination of the heartbeat signal.
default_value: 0
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Force Terminate (AFS_TERMINATE)

## Description
Software switch to immediately trigger vehicle termination.

## Tuning & Behavior
*   **Default Value:** 0 (Normal)
*   **Setting this to 1 in flight will terminate the vehicle.**
