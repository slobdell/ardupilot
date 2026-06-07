---
layout: parameter
name: SIM_PLD_HEIGHT
display_name: Simulated Precision Landing Height
description: Height of the simulated landing target above the ground.
default_value: 0
range: 0 100
units: m
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Precland.cpp#L62
---

# Simulated Precision Landing Height (SIM_PLD_HEIGHT)

## Description
`SIM_PLD_HEIGHT` defines the vertical position of the landing target (e.g., a rooftop, a landing platform, or a pole-mounted beacon) in SITL.

This allows you to test precision landing algorithms on elevated platforms rather than just on the flat ground.

## Tuning & Behavior
*   **Default:** 0 (Target is at ground level).
*   **Usage:** Set to the desired height in meters. The virtual sensor (IR-Lock) will report the target's position based on this height.