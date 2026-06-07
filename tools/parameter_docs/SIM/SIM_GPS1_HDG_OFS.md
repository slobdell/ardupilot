---
layout: parameter
name: SIM_GPS1_HDG_OFS
display_name: Simulated GPS 1 Heading Offset
description: An offset (in degrees) added to the simulated GPS heading (for Moving Baseline or NMEA heading).
default_value: 0
range: 0 360
units: deg
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS 1 Heading Offset (SIM_GPS1_HDG_OFS)

## Description
`SIM_GPS1_HDG_OFS` adds a constant error to the heading reported by the GPS.

This is only relevant if `SIM_GPS_HDG` is enabled (simulating a Dual Antenna GPS). It tests the EKF's ability to handle Compass/GPS yaw disagreement.

## Tuning & Behavior
*   **Default Value:** 0 deg.
*   **Testing:** Set to **90**. The EKF should trigger a "Yaw Alignment" error.