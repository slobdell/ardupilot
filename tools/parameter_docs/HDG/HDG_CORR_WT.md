---
layout: parameter
title: HDG_CORR_WT
name: Dock mode heading correction weight
group: HDG
---

# HDG_CORR_WT: Dock mode heading correction weight

## Description
This value describes how aggressively the vehicle tries to correct its heading to be on the desired line of approach.

## Values
- **Range:** 0.00 to 0.90
- **Increment:** 0.05
- **Default:** 0.75

## Description
This parameter controls the position of the "virtual target" used to align the vehicle with the dock. It acts as a "carrot on a stick" placed along the desired approach line between the vehicle and the dock.

- **Value:** Represents the fraction of the distance from the vehicle to the dock where the virtual target is placed (relative to the dock).
    - **0.75 (Default):** The target is placed at 75% of the distance to the dock (effectively 25% ahead of the vehicle) along the approach line.
    - **Higher Value (closer to 1.0):** The target is placed closer to the vehicle's current distance but projected onto the line. This might result in smoother but slower convergence to the line.
    - **Lower Value:** The target is placed closer to the dock. This forces a sharper, more aggressive turn to get onto the line quickly.

## Source Code
[ardupilot/Rover/mode_dock.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/mode_dock.cpp#L37)

