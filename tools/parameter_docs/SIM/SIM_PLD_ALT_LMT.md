---
layout: parameter
name: SIM_PLD_ALT_LMT
display_name: Simulation Precision Landing Max Altitude
description: The maximum altitude (in meters) at which the simulated sensor can detect the target.
default_value: 15
range: 0 100
units: m
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Precland.cpp#L94
---

# Simulation Precision Landing Max Altitude (SIM_PLD_ALT_LMT)

## Description
`SIM_PLD_ALT_LMT` simulates the "Range Limit" of your Precision Landing sensor (e.g. IR-Lock).

Real sensors have a limited effective range. If the drone is too high, the camera or sensor cannot see the beacon on the ground. This parameter tells the simulator to stop reporting valid target data when the drone climbs above this altitude.

## Tuning & Behavior
*   **Default:** 15 meters.
*   **Usage:** Set this to match the datasheet of your real sensor (e.g. IR-Lock MarkOne is typically effective up to ~15m in daylight).
*   **Testing:** Fly above this limit in SITL to verify that your failsafe or "Lost Target" logic engages correctly.