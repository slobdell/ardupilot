---
layout: parameter
name: SIM_TIME_JITTER
display_name: Simulated Time Jitter
description: The amount of random time variation (in microseconds) added to the simulator's main loop.
default_value: 0
range: 0 10000
units: us
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Time Jitter (SIM_TIME_JITTER)

## Description
`SIM_TIME_JITTER` adds "Instability" to the simulator's clock.

On a real flight controller, the main loop usually runs at exactly 400Hz or 1000Hz. However, CPU spikes can cause small delays. This parameter allows you to simulate that behavior in SITL to ensure the EKF and PID controllers don't crash or lose stability when the timing isn't perfect.