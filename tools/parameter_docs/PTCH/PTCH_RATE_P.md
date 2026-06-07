---
layout: parameter
name: PTCH_RATE_P
display_name: Pitch Rate P Gain
description: The proportional gain for the pitch rate controller. Corrects for errors between the desired pitch rate and the actual pitch rate.
default_value: 0.15
range: 0.08 0.35
units: 
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L78
---

# Pitch Rate P Gain (PTCH_RATE_P)

## Description
`PTCH_RATE_P` is the "Instant Reaction" gain for the elevator.

When you pull back on the stick, you command a pitch rate. This gain forces the elevator to move proportionally to the error between your command and the gyro's measurement.

## Tuning & Behavior
*   **Default Value:** 0.15.
*   **Too Low:** Mushy, slow pitch response.
*   **Too High:** Rapid "Dolphin" oscillations or flutter.