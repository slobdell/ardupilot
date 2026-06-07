---
layout: parameter
name: Q_TRANS_FAIL
display_name: QuadPlane Transition Failure Time
description: The maximum time (in seconds) allowed for a transition to complete.
default_value: 0
range: 0 20
units: s
group: Q
visual_asset_id: vtol_transition_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Transition Failure Time (Q_TRANS_FAIL)

## Description
`Q_TRANS_FAIL` is a safety timer.

If the plane tries to transition to forward flight but fails to reach the minimum airspeed (e.g. headwind too strong, motor failure), this timer triggers a failsafe action.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **10 seconds** for safety.