---
layout: parameter
name: PTCH_RATE_I
display_name: Pitch Rate I Gain
description: The integral gain for the pitch rate controller. Corrects for long-term errors or trim imbalances (e.g. nose-heavy CG).
default_value: 0.15
range: 0.01 0.6
units: 
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L78
---

# Pitch Rate I Gain (PTCH_RATE_I)

## Description
`PTCH_RATE_I` compensates for Center of Gravity (CG) errors.

If your plane is nose-heavy, the I-term will learn to hold a little bit of "Up Elevator" to keep the nose level without you having to hold the stick back.

## Tuning & Behavior
*   **Default Value:** 0.15.
*   **Recommendation:** Usually set equal to `PTCH_RATE_FF`.