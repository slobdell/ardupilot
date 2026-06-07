---
layout: parameter
name: SIM_GRPS_ENABLE
display_name: Gripper Servo Sim Enable
description: Enables the simulated servo-based gripper physics model.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Gripper_Servo.cpp#L32
---

# Gripper Servo Sim Enable (SIM_GRPS_ENABLE)

## Description
`SIM_GRPS_ENABLE` adds a functional virtual gripper to the drone.

This allows you to test "Cargo Hold" operations. The simulator models a servo-driven jaw that can pick up and drop a 1kg load when on the ground.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.
