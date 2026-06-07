---
layout: parameter
name: H_DDFP_BAT_V_MAX
display_name: DDVP Battery Voltage Max
description: The battery voltage at which the tail motor output is not scaled.
default_value: 0
range: 0 100
units: V
group: H
visual_asset_id: heli_tail_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L100
---

# DDVP Battery Voltage Max (H_DDFP_BAT_V_MAX)

## Description
`H_DDFP_BAT_V_MAX` sets the "Full Charge" reference.

When the battery is at this voltage, the mixer applies 100% of the requested throttle.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to 4.2V * Cell Count (e.g. 25.2V for 6S).