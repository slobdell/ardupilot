---
layout: parameter
name: SIM_TWIST_Z
display_name: Simulation Twist Z
description: Applies an external torque (angular acceleration) to the vehicle's Z-axis (yaw).
default_value: 0
range: -100 100
units: deg/s/s
group: SIM
visual_asset_id: physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L239
---

# Simulation Twist Z (SIM_TWIST_Z)

## Description
`SIM_TWIST_Z` applies an external rotation force to the yaw axis.

Use this to simulate a "Broken Propeller" scenario where one motor is producing more torque than the others, forcing the drone to spin.
