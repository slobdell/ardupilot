---
layout: parameter
name: RLL_RATE_FF
display_name: Roll Rate Feed-Forward
description: The feed-forward gain for the roll axis. Provides immediate control surface movement based on the commanded rate.
default_value: 0.345
range: 0 3.0
units: 
group: RLL
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Rate Feed-Forward (RLL_RATE_FF)

## Description
`RLL_RATE_FF` is the most important gain for Fixed Wing aircraft.

It tells the autopilot: "If I want 30 degrees/sec roll rate, I know I need to move the ailerons to 15 degrees." It provides the bulk of the control surface movement directly from the stick input, bypassing the error-correction loop.

## The Mathematics
$$ \text{Output} = k_{FF} \cdot \text{Rate}_{target} $$

## Tuning & Behavior
*   **Default Value:** 0.345.
*   **Recommendation:** Tune this *first* (or use Autotune). If `FF` is correct, the P and I terms have very little work to do.