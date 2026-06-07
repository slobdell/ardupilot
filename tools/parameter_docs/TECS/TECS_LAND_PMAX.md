---
layout: parameter
name: TECS_LAND_PMAX
display_name: TECS Landing Pitch Max
description: The maximum pitch angle (in degrees) allowed during the landing flare.
default_value: 0
range: 0 45
units: deg
group: TECS
visual_asset_id: tecs_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L100
---

# TECS Landing Pitch Max (TECS_LAND_PMAX)

## Description
`TECS_LAND_PMAX` prevents the autopilot from pulling the nose up too high during flare.

If the plane flares too aggressively, it might balloon up or strike its tail on the runway.

## Tuning & Behavior
*   **0 (Default):** Use normal pitch limits (`LIM_PITCH_MAX`).
*   **Recommendation:** Set to **10 or 15 degrees** to ensure a safe flare attitude.