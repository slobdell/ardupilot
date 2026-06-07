---
layout: parameter
name: SIM_GPS_GLITCH
display_name: Simulated GPS Glitch Offset
description: A static position offset (in meters) added to the primary simulated GPS.
default_value: 0
range: 0 100
units: m
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS Glitch Offset (SIM_GPS_GLITCH)

## Description
`SIM_GPS_GLITCH` simulates a "GPS Jump."

It adds a sudden, constant offset to the GPS coordinates. This is the best way to test if your `EKF_CHECK_SCALE` and failsafe settings are tight enough to detect a position jump before the drone flies away.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **10** or **20** meters while in LOITER mode and verify the drone triggers a failsafe rather than banking hard to chase the glitched position.