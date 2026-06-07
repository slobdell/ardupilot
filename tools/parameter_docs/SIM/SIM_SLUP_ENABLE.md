---
layout: parameter
name: SIM_SLUP_ENABLE
display_name: Slung Payload Sim Enable
description: Enables the simulated slung payload physics model.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_SlungPayload.cpp#L33
---

# Slung Payload Sim Enable (SIM_SLUP_ENABLE)

## Description
`SIM_SLUP_ENABLE` adds a swinging physical weight beneath the drone.

This is used for testing helicopter or multirotor "Slung Load" operations. The simulator calculates the pendulum physics, including the mass of the payload, the length of the line, and the drag on the object. The swinging payload exerts forces back on the drone, which can cause significant instability if not tuned correctly.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.
*   **Physics:** The payload is modeled as a point mass on a tether. It uses the vehicle's Earth-frame position and velocity to calculate tension and centripetal forces.