---
layout: parameter
name: PTCH_RATE_SMAX
display_name: Pitch Slew Rate Limit
description: Limits the rate of change of the pitch PID output to prevent mechanical stress or oscillation.
default_value: 0
range: 0 200
units: 
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L78
---

# Pitch Slew Rate Limit (PTCH_RATE_SMAX)

## Description
`PTCH_RATE_SMAX` limits how fast the elevator servo can move.

*   **0:** Disabled (Unlimited speed).

## Tuning & Behavior
*   **Use Case:** Enable this if you have large control surfaces that might cause structural damage if moved too quickly at high speed.