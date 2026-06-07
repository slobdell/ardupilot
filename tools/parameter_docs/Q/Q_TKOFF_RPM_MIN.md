---
layout: parameter
name: Q_TKOFF_RPM_MIN
display_name: QuadPlane Takeoff RPM Min
description: The minimum RPM required to detect a successful takeoff state.
default_value: 0
range: 0 10000
units: RPM
group: Q
visual_asset_id: vtol_takeoff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Takeoff RPM Min (Q_TKOFF_RPM_MIN)

## Description
`Q_TKOFF_RPM_MIN` is a safety check for RPM-controlled motors.

The autopilot will not release the landing gear or start the mission until the VTOL motors report at least this speed.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).