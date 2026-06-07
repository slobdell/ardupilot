---
layout: parameter
name: SIM_PLD_YAW
display_name: Simulation Precision Landing Target Yaw
description: The orientation (heading) of the simulated landing target.
default_value: 0
range: -180 180
units: deg
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Precland.cpp#L71
---

# Simulation Precision Landing Target Yaw (SIM_PLD_YAW)

## Description
`SIM_PLD_YAW` sets the heading of the virtual landing beacon or pad in SITL.

This is useful for testing sensors that report target orientation (like some 3D vision systems) or for verifying that the drone correctly aligns itself with the landing pad during the final touch-down phase.

## Tuning & Behavior
*   **Default:** 0 (Pointing North).
*   **Usage:** Set to any heading from -180 to 180 degrees.