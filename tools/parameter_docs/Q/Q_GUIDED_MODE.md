---
layout: parameter
name: Q_GUIDED_MODE
display_name: Enable VTOL in GUIDED mode
description: Controls whether the aircraft uses VTOL motors to hover at the destination when in Guided mode.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: q_guided_mode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L210
---

# Enable VTOL in GUIDED mode (Q_GUIDED_MODE)

## Description
`Q_GUIDED_MODE` determines how the QuadPlane behaves when receiving "Fly To" commands from a Ground Control Station (GCS) or companion computer.

*   **0: Disabled (Fixed Wing).** The plane flies to the guided waypoint as a fixed-wing aircraft and circles (loiters) around it. It does not use the vertical lift motors.
*   **1: Enabled (VTOL).** The plane flies to the guided waypoint. Once it arrives, it transitions to VTOL mode and hovers stationary at the target coordinates.

## The Engineer's View
Used in `ModeGuided::update()`.
If enabled, the vehicle will execute a `DO_VTOL_TRANSITION` automatically upon reaching the target radius. This is essential for "Drone-in-a-box" applications where the vehicle must precisely hover over a landing pad or delivery point.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** 
    *   **Mapping/Surveillance:** Keep at **0** to save battery (circling is much more efficient than hovering).
    *   **Delivery/Precision Inspection:** Set to **1** to allow precise hovering at the target.