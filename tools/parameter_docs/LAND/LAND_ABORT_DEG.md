---
layout: parameter
name: LAND_ABORT_DEG
display_name: Land Abort Angle
description: The pitch angle (in degrees) that triggers an automatic landing abort.
default_value: 0
range: 0 90
units: deg
group: LAND
visual_asset_id: land_abort_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Land Abort Angle (LAND_ABORT_DEG)

## Description
`LAND_ABORT_DEG` prevents the drone from landing if it is pitching too violently.

If the drone is fighting strong wind and pitching up/down more than this angle, it assumes the landing is unsafe and will climb back up (Go Around).

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **15 degrees** for fixed-wing or quadplanes to prevent propeller strikes.