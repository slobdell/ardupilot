---
layout: parameter
name: TECS_LAND_DAMP
display_name: TECS Landing Damping
description: Damping gain for the pitch demand during landing.
default_value: 0.5
range: 0.1 1.0
units: 
group: TECS
visual_asset_id: tecs_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L100
---

# TECS Landing Damping (TECS_LAND_DAMP)

## Description
`TECS_LAND_DAMP` smoothes out the pitch commands during the landing phase.

If the plane "Pumps" the elevator (rapidly pitching up and down) while trying to hold the glide slope, increasing this value can help dampen those oscillations.

## Tuning & Behavior
*   **Default Value:** 0.5.