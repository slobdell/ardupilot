---
layout: parameter
name: PTCH_RATE_IMAX
display_name: Pitch Rate I Max
description: The maximum integrator value for the pitch rate controller. Limits the amount of "trim" authority the autopilot has.
default_value: 0.666
range: 0 1
units: 
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L78
---

# Pitch Rate I Max (PTCH_RATE_IMAX)

## Description
`PTCH_RATE_IMAX` limits the authority of the I-term.

If your CG is dangerously far back or forward, the I-term will try to fix it by moving the elevator. This limit prevents it from using up *all* the elevator travel, ensuring you still have some control left for maneuvering.

## Tuning & Behavior
*   **Default Value:** 0.666.