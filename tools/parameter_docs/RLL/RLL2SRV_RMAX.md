---
layout: parameter
name: RLL2SRV_RMAX
display_name: Maximum Roll Rate
description: The maximum roll rate (in degrees per second) that the angle controller is allowed to demand.
default_value: 0
range: 0 180
units: deg/s
group: RLL
visual_asset_id: roll_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L42
---

# Maximum Roll Rate (RLL2SRV_RMAX)

## Description
`RLL2SRV_RMAX` acts as a "Speed Limit" for roll.

Even if the `TCONST` gain demands a roll rate of 300 deg/s to fix an error, this parameter caps the request.

*   **0:** Disabled (No limit).
*   **60:** Cap at 60 deg/s.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to match the physical capabilities of your airframe. If you ask for more than the plane can do, the integrator will wind up.
