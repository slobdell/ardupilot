---
layout: parameter
name: SIM_GPS1_ALT_OFS
display_name: Simulated GPS 1 Altitude Offset
description: An offset (in meters) added to the simulated GPS altitude.
default_value: 0
range: -100 100
units: m
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS 1 Altitude Offset (SIM_GPS1_ALT_OFS)

## Description
`SIM_GPS1_ALT_OFS` adds a constant error to the GPS altitude.

This is used to verify that the EKF can handle a disagreement between the Barometer (which reports correct altitude) and the GPS (which reports offset altitude).

## Tuning & Behavior
*   **Default Value:** 0 m.
*   **Testing:** Set to **20**. The EKF should initially report a large height innovation (error), then slowly shift the GPS bias or reject the GPS.