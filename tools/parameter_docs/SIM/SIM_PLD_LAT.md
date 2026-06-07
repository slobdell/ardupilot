---
layout: parameter
name: SIM_PLD_LAT
display_name: Simulated Precision Landing Latitude
description: The latitude of the simulated landing target beacon.
default_value: 0
range: -90 90
units: deg
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Precland.cpp#L44
---

# Simulated Precision Landing Latitude (SIM_PLD_LAT)

## Description
`SIM_PLD_LAT` defines the north/south coordinate of the landing target beacon used in the **Precision Landing** simulation.

This allows you to place the virtual beacon at a specific location on the map to test how the drone detects and navigates toward it from different approach angles.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Enter the exact latitude of the target.
*   **Integration:** Must be used in conjunction with [SIM_PLD_LON](SIM_PLD_LON.html) and [SIM_PLD_HEIGHT](SIM_PLD_HEIGHT.html).