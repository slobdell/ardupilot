---
layout: parameter
name: SIM_GPS_DELAY
display_name: Simulation GPS Delay
description: The latency (in cycles or ms, usually 1 = 1 update lag) introduced to the GPS signal.
default_value: 1
range: 0 10
units: 
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L111
---

# Simulation GPS Delay (SIM_GPS_DELAY)

## Description
`SIM_GPS_DELAY` simulates the processing lag of a real GPS module.

Real GPS units don't report position instantly; there is a calculation delay.

## Tuning & Behavior
*   **Default Value:** 1.
*   **Testing:** Increasing this can stress-test the EKF's ability to handle delayed measurements.
