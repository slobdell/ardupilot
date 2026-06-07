---
layout: parameter
title: HDG_CORR_EN
name: Dock mode heading correction enable/disable
group: HDG
---

# HDG_CORR_EN: Dock mode heading correction enable/disable

## Description
When enabled, the autopilot modifies the path to approach the target head-on along the desired line of approach (`DOCK_DIR`) in Dock mode.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Enabled |

## Description
This parameter forces the Rover (or Boat) to align with a specific compass heading (`DOCK_DIR`) *before* it reaches the dock, ensuring a straight-in approach. This is useful for docking into a slip or connecting to a charging station where the angle of arrival is critical.

- **Enabled (1):** The vehicle generates a virtual waypoint along the approach vector to steer the vehicle onto the correct line.
- **Disabled (0):** The vehicle drives directly towards the dock from its current position, regardless of the angle.

## Source Code
[ardupilot/Rover/mode_dock.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/mode_dock.cpp#L29)

