---
layout: parameter
name: SIM_PLD_LON
display_name: Simulated Precision Landing Longitude
description: The longitude of the simulated landing target beacon.
default_value: 0
range: -180 180
units: deg
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Precland.cpp#L53
---

# Simulated Precision Landing Longitude (SIM_PLD_LON)

## Description
`SIM_PLD_LON` defines the east/west coordinate of the landing target beacon used in the **Precision Landing** simulation.

This allows you to place the virtual beacon at a specific location on the map to test how the drone detects and navigates toward it from different approach angles.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Enter the exact longitude of the target.
*   **Integration:** Must be used in conjunction with [SIM_PLD_LAT](SIM_PLD_LAT.html) and [SIM_PLD_HEIGHT](SIM_PLD_HEIGHT.html).