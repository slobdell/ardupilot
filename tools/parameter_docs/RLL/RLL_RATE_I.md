---
layout: parameter
name: RLL_RATE_I
display_name: Roll Rate I Gain
description: The integral gain for the roll rate controller. Corrects for long-term errors or trim imbalances.
default_value: 0.15
range: 0.01 0.6
units: 
group: RLL
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Rate I Gain (RLL_RATE_I)

## Description
`RLL_RATE_I` handles "Drift" and "Trim" on the roll axis.

If one wing is heavier than the other, or if your ailerons are slightly warped, the plane will constantly want to roll to one side. The I-term builds up aileron pressure over time to cancel out this bias and keep the roll rate at zero (level flight).

## Tuning & Behavior
*   **Default Value:** 0.15.
*   **Recommendation:** Usually set equal to `RLL_RATE_FF` or found via Autotune.