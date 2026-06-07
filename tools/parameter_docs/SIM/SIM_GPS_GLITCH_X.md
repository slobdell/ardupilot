---
layout: parameter
name: SIM_GPS_GLITCH_X
display_name: Simulation GPS Glitch X
description: Adds a constant offset (in meters) to the GPS X position to simulate a glitch or drift.
default_value: 0
range: -100 100
units: m
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L118
---

# Simulation GPS Glitch X (SIM_GPS_GLITCH_X)

## Description
`SIM_GPS_GLITCH_X` allows you to inject a GPS failure mid-flight.

By changing this parameter via MAVLink while flying in SITL, you can instantly shift the reported GPS position.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **20** while Loitering. The drone should lean hard to "correct" its position (actually moving away from the true target), then EKF might reject the glitch. Useful for testing EKF failsafe logic.
