---
layout: parameter
name: Q_TILT_YAW_ANGLE
display_name: Tilt Rotor Yaw Angle
description: The maximum angle (in degrees) for yaw control using tilt rotors.
default_value: 0
range: 0 30
units: deg
group: Q
visual_asset_id: vtol_tilt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tilt Rotor Yaw Angle (Q_TILT_YAW_ANGLE)

## Description
`Q_TILT_YAW_ANGLE` enables "Vectored Yaw" for tilt-rotors.

If your tilt servos are strong enough, you can differential-tilt them (left motor up, right motor down) to yaw the aircraft without using a rudder. This parameter limits how much they can move for this purpose.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **10-15 degrees** if your airframe supports it (Requires `Q_TILT_TYPE` = 2).