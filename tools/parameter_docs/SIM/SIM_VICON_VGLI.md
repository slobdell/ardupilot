---
layout: parameter
name: SIM_VICON_VGLI
display_name: Simulation Vicon Velocity Glitch
description: The magnitude (in m/s) of a sudden velocity step-change injected into the Vicon data.
default_value: 0
range: 0 10
units: m/s
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SITL.cpp#L619
---

# Simulation Vicon Velocity Glitch (SIM_VICON_VGLI)

## Description
`SIM_VICON_VGLI` injects a false "Speed Spike" into the external navigation data.

Even if the drone is hovering perfectly still, this parameter makes the simulated motion capture system report that the drone is suddenly moving vertically at high speed. This tests how the EKF handles conflicting data (accelerometers say "stopped," Vicon says "moving").

## Tuning & Behavior
*   **Default:** 0 m/s.
*   **Usage:** Set to **5.0** to simulate a tracking error where the system momentarily loses lock and reports a massive velocity spike.
*   **Note:** This applies the glitch to the **Down** (Vertical) velocity.