---
layout: parameter
name: LAND_PF_SEC
display_name: Land Pre-Flare Time
description: The time (in seconds) before the flare point to begin the pre-flare maneuver.
default_value: 0
range: 0 10
units: s
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Pre-Flare Time (LAND_PF_SEC)

## Description
`LAND_PF_SEC` triggers the pre-flare based on time-to-impact.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).