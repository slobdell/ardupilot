---
layout: parameter
name: PTCH2SRV_RMAX_UP
display_name: Pitch Up Max Rate
description: The maximum pitch-up rate (in degrees per second) that the angle controller is allowed to demand.
default_value: 0
range: 0 100
units: deg/s
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L42
---

# Pitch Up Max Rate (PTCH2SRV_RMAX_UP)

## Description
`PTCH2SRV_RMAX_UP` limits the G-force of a pull-up maneuver.

If you set this to a reasonable value (e.g. 60 deg/s), the autopilot will never try to pull the nose up faster than that, even if you yank the stick back or the navigation controller demands a steep climb. This protects the wings from snapping.

## Tuning & Behavior
*   **Default Value:** 0 (Unlimited).
*   **Recommendation:** Set to match your airframe's structural limits or your desired flight style.
