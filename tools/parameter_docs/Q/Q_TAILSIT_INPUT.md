---
layout: parameter
name: Q_TAILSIT_INPUT
display_name: Tailsitter Input Type
description: Selects the control frame (Body or Earth) for pilot inputs during tailsitter hover.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Input Type (Q_TAILSIT_INPUT)

## Description
`Q_TAILSIT_INPUT` defines how the pilot's sticks behave when the plane is standing on its tail (vertical).

*   **0 (Body Frame):** The sticks follow the drone's perspective. If you push the "Roll" stick, the drone rotates around its own spine, which looks like a "Yaw" spin to someone standing on the ground.
*   **1 (Earth Frame):** The sticks follow the pilot's perspective. "Roll" always tilts the drone left/right relative to the horizon, regardless of how the drone is rotated.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Most pilots find **1 (Earth Frame)** much more intuitive for hovering, as it makes the tailsitter feel like a standard multirotor.