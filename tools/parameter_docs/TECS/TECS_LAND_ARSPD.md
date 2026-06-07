---
layout: parameter
name: TECS_LAND_ARSPD
display_name: TECS Landing Airspeed
description: The target airspeed (in m/s) during the automatic landing approach.
default_value: -1
range: -1 40
units: m/s
group: TECS
visual_asset_id: tecs_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L100
---

# TECS Landing Airspeed (TECS_LAND_ARSPD)

## Description
`TECS_LAND_ARSPD` overrides the cruise speed during the final approach.

Normally, the plane flies at `AIRSPEED_CRUISE`. But for landing, you usually want to fly slower (closer to stall speed) to reduce energy.

## Tuning & Behavior
*   **-1 (Default):** Use `AIRSPEED_CRUISE`.
*   **Value:** Set to **1.3 x Stall Speed** for a safe, slow approach.