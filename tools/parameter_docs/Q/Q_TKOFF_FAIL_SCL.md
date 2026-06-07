---
layout: parameter
name: Q_TKOFF_FAIL_SCL
display_name: QuadPlane Takeoff Failure Scaler
description: A scaling factor for the takeoff failure detection timeout.
default_value: 0
range: 0 5
units: 
group: Q
visual_asset_id: vtol_takeoff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Takeoff Failure Scaler (Q_TKOFF_FAIL_SCL)

## Description
`Q_TKOFF_FAIL_SCL` adjusts how long the drone tries to climb before giving up.

If the drone is at full throttle but not gaining altitude (e.g., battery is dead or payload is too heavy), the autopilot will disarm to save the motors. This parameter extends that timeout.

## Tuning & Behavior
*   **Default Value:** 0 (Standard timeout).
*   **High Value:** Allows longer struggle before disarming.