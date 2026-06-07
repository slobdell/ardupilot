---
layout: parameter
name: SIM_DRIFT_SPEED
display_name: Simulation GPS Drift Speed
description: The rate (in m/s) at which the simulated GPS position drifts away from the true position.
default_value: 0.05
range: 0 0.5
units: m/s
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L102
---

# Simulation GPS Drift Speed (SIM_DRIFT_SPEED)

## Description
`SIM_DRIFT_SPEED` simulates the "Wandering" effect of GPS.

Real GPS position is never perfectly still; it slowly drifts around a central point due to atmospheric changes. This parameter controls how fast that drift moves.

## Tuning & Behavior
*   **Default Value:** 0.05 m/s.
*   **Testing:** Increase to **0.2** to test if your Loiter PID tuning is tight enough to hold position against a "moving" GPS target.
