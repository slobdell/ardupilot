---
layout: parameter
name: Q_TKOFF_ARSP_LIM
display_name: QuadPlane Takeoff Airspeed Limit
description: The airspeed (in m/s) limit for vertical takeoff. If exceeded, the aircraft may abort the takeoff or limit pitch to prevent backward drift.
default_value: 0
range: 0 20
units: m/s
group: Q
visual_asset_id: vtol_takeoff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Takeoff Airspeed Limit (Q_TKOFF_ARSP_LIM)

## Description
`Q_TKOFF_ARSP_LIM` is a safety check for high-wind operations.

If you try to take off vertically in a hurricane, the wing will generate lift even though you are in Copter mode. This can confuse the controller. This parameter sets a limit: if the airspeed is higher than this value while taking off, the autopilot will restrict how far it leans back (to fight the wind) or abort the takeoff entirely to prevent a loss of control.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **15 m/s** if you operate in gusty environments.
