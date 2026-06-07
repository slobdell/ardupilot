---
layout: parameter
name: SIM_PLD_ORIENT
display_name: Simulation Precision Landing Orientation
description: The mounting orientation of the simulated precision landing sensor.
default_value: 25
range: 0 38
units: 
group: SIM
visual_asset_id: prx_orientation_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Precland.cpp#L109
---

# Simulation Precision Landing Orientation (SIM_PLD_ORIENT)

## Description
`SIM_PLD_ORIENT` tells the simulator which way the virtual camera is pointing.

By default, Precision Landing cameras (like IR-Lock) are mounted pointing straight down. However, some advanced setups use a gimballed camera or a fixed forward-facing camera for approach. This parameter allows you to test those configurations in SITL.

## Tuning & Behavior
*   **25 (Default):** Pitch 270 (Straight Down).
*   **0:** None (Straight Forward).
*   **Usage:** Must match the `PLND_ORIENT` parameter in your vehicle's configuration to ensure the EKF correctly interprets the target's position relative to the drone.