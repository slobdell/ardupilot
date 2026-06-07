---
layout: parameter
name: H_COL2YAW
display_name: Collective-Yaw Mixing
description: Feed-forward compensation to automatically add rudder input when collective pitch is increased.
default_value: 0
range: -2 2
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_Single.cpp
---

# Collective-Yaw Mixing (H_COL2YAW)

## Description
Compensates for the changing torque of the main rotor as collective pitch increases. By automatically adding a pre-calculated amount of tail rotor thrust, this reduces the work required by the yaw PID controller and results in a more stable heading during aggressive climbs.