---
layout: parameter
name: AUTO_TRIM
display_name: Automatic servo trim
description: This enables automatic servo trim in flight. Servos will be trimmed in stabilized flight modes when the aircraft is close to level.
default_value: 0
range: 0 1
units: 
group: AUTO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channels.cpp
---

# Automatic servo trim (AUTO_TRIM)

## Description
Continuously learns and saves the required servo trim offsets while flying in stabilized modes. This compensates for slight physical imbalances in the airframe without requiring manual trim adjustments.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Only active in stabilized modes (e.g., FBWA) when the pilot is not providing stick inputs.**