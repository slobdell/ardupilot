---
layout: parameter
name: SIM_GPS_JAM
display_name: Simulated GPS Jamming
description: Enables simulation of GPS jamming (signal interference).
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS Jamming (SIM_GPS_JAM)

## Description
`SIM_GPS_JAM` simulates a "Denial of Service" attack on your GPS.

When enabled, the GPS continues to report a "3D Fix" (usually), but the signal quality degrades, and the position may drift or freeze, mimicking the behavior of a jammed receiver.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Jamming Active.
