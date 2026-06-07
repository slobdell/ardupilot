---
layout: parameter
name: LAND_REPOSITION
display_name: Pilot Land Reposition Enable
description: Enables the pilot to "nudge" the drone's horizontal position during an automatic landing.
default_value: 1
range: 0 1
units: 
group: LAND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L381
---

# Pilot Land Reposition Enable (LAND_REPOSITION)

## Description
`LAND_REPOSITION` allows you to steer the drone while it is landing itself.

If the drone is performing an automatic land (e.g. at the end of a Return-to-Launch), it might head toward a patch of long grass or a small puddle. If this parameter is **Enabled (1)**, you can use your transmitter sticks to "nudge" the drone left, right, forward, or backward without cancelling the landing sequence. The drone will continue its vertical descent while moving horizontally based on your inputs.

*   **1: Enabled (Default).** Active pilot steering allowed during LAND.
*   **0: Disabled.** The drone will land exactly where it is, ignoring pilot sticks.

## Tuning & Behavior
*   **Safety:** This is a vital safety feature. It allows you to avoid last-second obstacles on the ground that the GPS might not be precise enough to miss.