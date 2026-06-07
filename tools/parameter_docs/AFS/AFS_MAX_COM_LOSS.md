---
layout: parameter
name: AFS_MAX_COM_LOSS
display_name: Maximum number of comms loss events
description: Maximum number of comms loss events before the aircraft stops returning to mission on comms recovery. Use zero to allow for any number of comms loss events.
default_value: 0
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Maximum number of comms loss events (AFS_MAX_COM_LOSS)

## Description
Limit on how many times communication can be lost before the aircraft refuses to resume its mission.

## Tuning & Behavior
*   **Default Value:** 0 (Unlimited)
