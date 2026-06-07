---
layout: parameter
name: SIM_GPS_VERR
display_name: Simulation GPS Velocity Error
description: Adds a constant error (in m/s) to the simulated GPS velocity reading.
default_value: 0
range: 0 5
units: m/s
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L111
---

# Simulation GPS Velocity Error (SIM_GPS_VERR)

## Description
`SIM_GPS_VERR` simulates a GPS receiver that reports incorrect speeds.

This is a common failure mode in real-world "Urban Canyons," where signal multipath can cause the GPS to think the drone is moving at 2 m/s even when it is perfectly still. This parameter helps you test the EKF's ability to reject bad velocity data and rely more on the accelerometers.