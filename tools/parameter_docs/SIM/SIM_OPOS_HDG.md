---
layout: parameter
name: SIM_OPOS_HDG
display_name: Simulated Original Position (Heading)
description: The starting heading (in degrees) for the vehicle in the simulator.
default_value: 353.0
range: 0 360
units: deg
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Original Position (Heading) (SIM_OPOS_HDG)

## Description
`SIM_OPOS_HDG` sets the direction the vehicle faces when it spawns.

*   **0:** North
*   **90:** East
*   **180:** South
*   **270:** West

## Tuning & Behavior
*   **Default Value:** 353.0 degrees.
*   **Recommendation:** Align this with the "virtual runway" at your test site to make takeoff easier.