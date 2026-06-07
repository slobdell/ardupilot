---
layout: parameter
name: LAND_PF_ARSPD
display_name: Land Pre-Flare Airspeed
description: The target airspeed (in m/s) during the pre-flare stage.
default_value: 0
range: 0 30
units: m/s
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Pre-Flare Airspeed (LAND_PF_ARSPD)

## Description
`LAND_PF_ARSPD` sets the speed limit for the "Final Approach."

This is typically slower than cruise but faster than stall speed. It bridges the gap between flying speed and landing speed.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).