---
layout: parameter
name: LAND_FLARE_SEC
display_name: Land Flare Time
description: The time (in seconds) before expected touchdown to begin the flare maneuver.
default_value: 2.0
range: 0 5
units: s
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Flare Time (LAND_FLARE_SEC)

## Description
`LAND_FLARE_SEC` is a time-based backup for starting the landing flare.

The autopilot calculates when it *expects* to hit the ground based on its current sink rate. If that time becomes less than this value, it will start the flare even if it hasn't reached `LAND_FLARE_ALT` yet. This helps in high-sink-rate situations where the plane might otherwise hit the ground before the altitude-based trigger can react.

## Tuning & Behavior
*   **Default Value:** 2.0 seconds.