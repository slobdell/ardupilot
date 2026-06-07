---
layout: parameter
name: SIM_GPS2_HDG
display_name: Simulated GPS 2 Heading
description: The heading (in degrees) reported by the second GPS.
default_value: 0
range: 0 360
units: deg
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS 2 Heading (SIM_GPS2_HDG)

## Description
`SIM_GPS2_HDG` sets the "True North" for the secondary GPS if it is a "Moving Baseline" unit.

By setting this to a value different from the actual vehicle heading, you can test how the autopilot handles "GPS Yaw" errors or alignment issues.

## Tuning & Behavior
*   **Default Value:** 0 (Matches vehicle heading).