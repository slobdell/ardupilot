---
layout: parameter
name: H_DDFP_BAT_IDX
display_name: DDVP Battery Index
description: The battery monitor instance used for tail motor voltage compensation.
default_value: 0
range: 0 10
units: 
group: H
visual_asset_id: heli_tail_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L100
---

# DDVP Battery Index (H_DDFP_BAT_IDX)

## Description
`H_DDFP_BAT_IDX` tells the tail mixer which battery to watch.

If you have a separate battery for the tail motor (uncommon) or if your main battery is on Monitor 2, set this index accordingly.

*   **0:** Battery Monitor 1.
*   **1:** Battery Monitor 2.