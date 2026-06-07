---
layout: parameter
name: DOCK_HDG_CORR_EN
display_name: Dock Heading Correction Enable
description: Enables the autopilot to steer onto a specific approach line for docking, rather than just heading straight for the coordinate.
default_value: 0
range: 0 1
units: 
group: DOCK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/mode_dock.cpp#L29
---

# Dock Heading Correction Enable (DOCK_HDG_CORR_EN)

## Description
`DOCK_HDG_CORR_EN` is used for precision docking where the vehicle must enter the dock from a specific direction (e.g. into a narrow charging slot).

If disabled, the vehicle flies directly from its current position to the dock's location. If enabled, the vehicle will first navigate to a "Capture Point" and then follow a straight vector (the "Docking Lane") to ensure it arrives perfectly squared up to the target.

*   **1: Enabled.** Vehicle attempts a straight-in head-on approach.
*   **0: Disabled.** Vehicle flies direct-to-target.

## Tuning & Behavior
*   **Default:** 0.
*   **Requirement:** Requires the dock to provide its own heading information via MAVLink or a beacon.