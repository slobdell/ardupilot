---
layout: parameter
name: SIM_GPS_ACC
display_name: Simulated GPS Accuracy
description: The positional accuracy (in meters) reported by the simulated GPS 1.
default_value: 0.3
range: 0 10
units: m
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS Accuracy (SIM_GPS_ACC)

## Description
`SIM_GPS_ACC` defines the "Radius of Confusion" for the virtual GPS.

It sets the value reported in the MAVLink `GPS_RAW_INT.h_acc` field. While it doesn't always add physical noise to the position (see `SIM_GPS_NOISE`), it tells the EKF how much to trust the position.

## Tuning & Behavior
*   **Default Value:** 0.3 m.
*   **Recommendation:** Set to **0.1** for "Ideal" GPS or **2.0** to simulate poor signal conditions.