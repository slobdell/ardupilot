---
layout: parameter
name: SIM_TWIST_Y
display_name: Simulation Twist Y
description: Applies an external torque (angular acceleration) to the vehicle's Y-axis (pitch).
default_value: 0
range: -100 100
units: deg/s/s
group: SIM
visual_asset_id: physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L238
---

# Simulation Twist Y (SIM_TWIST_Y)

## Description
`SIM_TWIST_Y` applies an external rotation force to the pitch axis.

This is useful for simulating a mechanical failure (like a loose motor mount) or an external snag (like a payload cable pulling on the frame). It tests the attitude controller's ability to maintain level flight under constant torque.
