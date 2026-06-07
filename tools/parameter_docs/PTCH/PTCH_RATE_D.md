---
layout: parameter
name: PTCH_RATE_D
display_name: Pitch Rate D Gain
description: The derivative gain for the pitch rate controller. Dampens the pitch response to prevent overshoot and bouncing.
default_value: 0.004
range: 0.001 0.03
units: 
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L78
---

# Pitch Rate D Gain (PTCH_RATE_D)

## Description
`PTCH_RATE_D` stops the nose from bouncing.

When you release the elevator stick, the plane should stop pitching instantly. If it bounces up and down before settling, you need more D.

## Tuning & Behavior
*   **Default Value:** 0.004.
*   **Recommendation:** Tune carefully. Too much D causes rapid vibration and hot servos.