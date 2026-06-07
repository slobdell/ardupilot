---
layout: parameter
name: SIM_ADSB_RADIUS
display_name: Simulated ADSB Radius
description: The radius (in meters) around the home location where simulated ADSB aircraft will appear.
default_value: 10000
range: 1000 100000
units: m
group: SIM
visual_asset_id: sim_adsb_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated ADSB Radius (SIM_ADSB_RADIUS)

## Description
`SIM_ADSB_RADIUS` sets the size of the "arena" for the simulated air traffic.

Simulated planes will spawn and fly within this distance from your home point.

## Tuning & Behavior
*   **Default Value:** 10000 m (10 km).
*   **Recommendation:** Lower this to **1000 or 2000** if you want the traffic to be denser and closer to your drone for easier testing.