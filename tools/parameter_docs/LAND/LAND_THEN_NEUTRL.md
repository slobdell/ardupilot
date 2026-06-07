---
layout: parameter
name: LAND_THEN_NEUTRL
display_name: Land Then Neutralize Servos
description: Controls whether servos are moved to neutral after landing is complete.
default_value: 0
range: 0 1
units: 
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Then Neutralize Servos (LAND_THEN_NEUTRL)

## Description
`LAND_THEN_NEUTRL` protects your servos after the flight.

Once the plane has landed and disarmed, the autopilot usually holds the last known control positions (e.g., elevator up). This parameter forces all surfaces to their center (neutral) position.

## Tuning & Behavior
*   **0:** Disabled (Hold last position).
*   **1:** Enabled (Center all surfaces).
*   **Recommendation:** Enable this to prevent servo buzz on the ground.