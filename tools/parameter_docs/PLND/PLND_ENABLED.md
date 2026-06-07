---
layout: parameter
name: PLND_ENABLED
display_name: Precision Landing Enable
description: Enables the precision landing system, allowing the drone to land on a specific visual target (e.g., IRLock or MAVLink beacon).
default_value: 0
range: 0 1
units: 
group: PLND
visual_asset_id: precland_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L40
---

# Precision Landing Enable (PLND_ENABLED)

## Description
`PLND_ENABLED` activates the "Visual Landing" system.

Standard GPS landing is accurate to about 1-2 meters. Precision Landing (PrecLand) uses a sensor (like an IRLock camera or an onboard computer) to see a target on the ground and guide the drone onto it with centimeter-level accuracy.

*   **0: Disabled.**
*   **1: Enabled.**

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Trigger:** Precision landing is typically used in the `LAND` flight mode. Once enabled, the drone will look for the target as it descends.
