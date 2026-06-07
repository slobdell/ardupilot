---
layout: parameter
name: SIM_PLD_OPTIONS
display_name: Simulation Precision Landing Options
description: Bitmask for advanced simulated sensor behaviors (e.g., glitches).
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Precland.cpp#L116
---

# Simulation Precision Landing Options (SIM_PLD_OPTIONS)

## Description
`SIM_PLD_OPTIONS` allows developers to inject realistic faults into the simulated Precision Landing sensor.

*   **Bit 0 (1):** Enable Glitches. Randomly drops the target valid flag or shifts the target position momentarily to test the EKF's resilience to bad data.

## Tuning & Behavior
*   **Default:** 0 (Perfect sensor).
*   **Recommendation:** Set to **1** when tuning your landing logic to ensure the drone doesn't make sudden, dangerous jerks if the sensor data becomes noisy.