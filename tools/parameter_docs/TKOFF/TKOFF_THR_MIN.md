---
layout: parameter
name: TKOFF_THR_MIN
display_name: Takeoff Minimum Throttle
description: The minimum throttle percentage applied during automatic takeoff. Ensures the motor doesn't drop to idle if the pitch controller demands a descent.
default_value: 0
range: 0 100
units: '%'
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1254
---

# Takeoff Minimum Throttle (TKOFF_THR_MIN)

## Description
`TKOFF_THR_MIN` forces the motor to keep pulling during the takeoff climb.

Normally, the TECS controller manages throttle. If the plane climbs too steeply and airspeed drops, TECS adds power. If the plane is fast and climbing well, TECS might reduce power. This parameter sets a "Floor" to prevent the throttle from dropping too low, ensuring a strong, positive climb-out.

## The Engineer's View
Used when `TKOFF_OPTIONS` bit 0 is set (Allow variable throttle).
The throttle demand is clamped: `output = max(output, TKOFF_THR_MIN)`.

## Tuning & Behavior
*   **Default Value:** 0 (Use `THR_MIN`).
*   **Recommendation:** Set to **50% or 75%** for hand-launched planes to guarantee they have energy to clear obstacles, even if the airspeed sensor thinks the plane is already fast enough.