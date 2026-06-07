---
layout: parameter
name: Q_TAILSIT_ANGLE
display_name: Tailsitter Transition Angle
description: The pitch angle (in degrees) at which the tailsitter transitions from VTOL to fixed-wing control logic.
default_value: 45
range: 10 80
units: deg
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Transition Angle (Q_TAILSIT_ANGLE)

## Description
`Q_TAILSIT_ANGLE` sets the "Switching Point" during a transition.

As the tailsitter leans forward to gain speed, there is a moment where it stops being a "Drone" and starts being a "Plane." This parameter defines that halfway point.

## Tuning & Behavior
*   **Default Value:** 45 degrees.
*   **Recommendation:** Set to **45** for most designs. If the plane has a very high stall speed, you might need a higher angle (e.g. **60**) to keep the VTOL motors helping for longer.