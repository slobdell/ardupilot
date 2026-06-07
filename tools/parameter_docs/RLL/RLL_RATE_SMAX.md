---
layout: parameter
name: RLL_RATE_SMAX
display_name: Roll Slew Rate Limit
description: Limits the rate of change of the roll PID output to prevent mechanical stress or oscillation.
default_value: 0
range: 0 200
units: 
group: RLL
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Slew Rate Limit (RLL_RATE_SMAX)

## Description
`RLL_RATE_SMAX` prevents the servos from moving too fast.

If the PID loop commands a jump from 0% to 100% aileron in 1 millisecond, this limiter slows it down to a more reasonable speed.

*   **0:** Disabled (Unlimited).
*   **Value:** Maximum percentage change per second.

## Tuning & Behavior
*   **Recommendation:** Usually left at **0** for planes. Can be used if you have very slow servos or fragile linkages.