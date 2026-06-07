---
layout: parameter
name: LAND_PF_ALT
display_name: Land Pre-Flare Altitude
description: The altitude (in meters) to begin the pre-flare maneuver.
default_value: 0
range: 0 30
units: m
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Pre-Flare Altitude (LAND_PF_ALT)

## Description
`LAND_PF_ALT` adds a "Slow Down" zone before the flare.

At this altitude, the plane will reduce its airspeed target to `LAND_PF_ARSPD`. This allows high-speed aircraft to bleed off energy safely before they are right on top of the runway.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **10-15m** for fast jets or slippery gliders.