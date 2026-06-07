---
layout: parameter
name: RLL_RATE_IMAX
display_name: Roll Rate I Max
description: The maximum integrator value for the roll rate controller. Limits the amount of "trim" authority the autopilot has.
default_value: 0.666
range: 0 1
units: 
group: RLL
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Rate I Max (RLL_RATE_IMAX)

## Description
`RLL_RATE_IMAX` limits how far the autopilot can move the ailerons to correct for a persistent error (like a bent wing or extreme crosswind).

*   **Default (0.666):** Allows the I-term to use up to 66% of the servo travel.

## Tuning & Behavior
*   **Recommendation:** Leave at default. If set too low, the plane might not be able to hold level flight if it is badly out of trim.