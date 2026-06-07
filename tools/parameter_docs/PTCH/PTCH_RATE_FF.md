---
layout: parameter
name: PTCH_RATE_FF
display_name: Pitch Rate Feed-Forward
description: The feed-forward gain for the pitch axis. Provides immediate control surface movement based on the commanded rate.
default_value: 0.345
range: 0 3.0
units: 
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L78
---

# Pitch Rate Feed-Forward (PTCH_RATE_FF)

## Description
`PTCH_RATE_FF` is the primary gain for pitch control.

It predicts how much elevator is needed to achieve a certain pitch rate based on the physics of the airframe.

## Tuning & Behavior
*   **Default Value:** 0.345.
*   **Recommendation:** This is the most critical parameter to tune. Use Autotune or increase slowly until the pitch rate matches the stick input perfectly.