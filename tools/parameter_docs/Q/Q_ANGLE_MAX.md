---
layout: parameter
name: Q_ANGLE_MAX
display_name: QuadPlane Maximum Tilt Angle
description: The maximum lean angle (in centi-degrees) allowed in VTOL flight modes (QSTABILIZE, QHOVER, QLOITER).
default_value: 3000
range: 1000 8000
units: cdeg
group: Q
visual_asset_id: angle_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Maximum Tilt Angle (Q_ANGLE_MAX)

## Description
`Q_ANGLE_MAX` sets the "Lean Limit" of your QuadPlane while it is in a hover mode.

If you push the stick all the way to the side, the drone will tilt over until it hits this limit and then stop. This prevents the drone from flipping over or losing too much vertical thrust.

## The Engineer's View
Defined in `quadplane.cpp`.
This parameter is used by the `AC_AttitudeControl` library specifically for VTOL modes. It is separate from the fixed-wing `LIM_PITCH_MAX/MIN` and `LIM_ROLL_CD` parameters.

## Tuning & Behavior
*   **Default Value:** 3000 (30 degrees).
*   **Recommendation:** Set to **30-45 degrees**.
*   **High Performance:** If you need to move fast in QLOITER or buck high winds, increase this to **4500 (45 degrees)**.