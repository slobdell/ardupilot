---
layout: parameter
name: AFS_MAX_GPS_LOSS
display_name: Maximum number of GPS loss events
description: Maximum number of GPS loss events before the aircraft stops returning to mission on GPS recovery. Use zero to allow for any number of GPS loss events.
default_value: 0
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Maximum number of GPS loss events (AFS_MAX_GPS_LOSS)

## Description
Limit on how many times GPS signal can be lost before the aircraft refuses to resume its mission.

## Tuning & Behavior
*   **Default Value:** 0 (Unlimited)
