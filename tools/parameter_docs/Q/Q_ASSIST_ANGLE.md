---
layout: parameter
name: Q_ASSIST_ANGLE
display_name: QuadPlane Assist Angle
description: The bank angle (in degrees) above which QuadPlane assistance is automatically enabled to prevent a loss of control.
default_value: 0
range: 0 90
units: deg
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Assist Angle (Q_ASSIST_ANGLE)

## Description
`Q_ASSIST_ANGLE` is an emergency "Uprighting" mechanism.

If the plane tilts past this angle (e.g., 60 degrees) while in a fixed-wing mode, the VTOL motors will immediately engage to level the aircraft. This is useful for recovering from a stall or a pilot mistake.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **60** for large, slow-rolling planes. Set to **0** for aerobatic planes that are intended to fly at extreme angles.
*   **Safety:** This can save an airframe during a high-speed stall where the control surfaces have lost authority.