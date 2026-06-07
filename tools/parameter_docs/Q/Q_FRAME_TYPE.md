---
layout: parameter
name: Q_FRAME_TYPE
display_name: QuadPlane Frame Type
description: Defines the motor rotation direction and orientation (e.g., X, Plus, V) for the VTOL motors.
default_value: 1
range: 0 19
units: 
group: Q
visual_asset_id: q_frame_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L137
---

# QuadPlane Frame Type (Q_FRAME_TYPE)

## Description
`Q_FRAME_TYPE` specifies the geometry of the frame class selected in `Q_FRAME_CLASS`.

*   **1: X (Default).** Motors are at 45 degrees to the nose. (Standard for almost all QuadPlanes).
*   **0: Plus (+).** Motors are at 0/90/180/270 degrees.
*   **2: V.**
*   **3: H.** H-frame quad.

## The Engineer's View
Used by `AP_MotorsMatrix` to populate the roll/pitch/yaw factors for each motor output.
Most QuadPlanes use an **X** configuration because it keeps the propellers out of the camera view and allows the fuselage to pass between the rotors.

## Tuning & Behavior
*   **Default Value:** 1 (X)
*   **Recommendation:** Leave at **1** for standard builds.
*   **Reboot Required:** Yes.