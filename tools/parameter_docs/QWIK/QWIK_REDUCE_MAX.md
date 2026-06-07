---
layout: parameter
name: QWIK_REDUCE_MAX
display_name: Quicktune Max Gain Reduction
description: Limits how much Quicktune is allowed to lower your gains below their original starting values.
default_value: 20
range: 0 100
units: %
group: QWIK
visual_asset_id: quicktune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L99
---

# Quicktune Max Gain Reduction (QWIK_REDUCE_MAX)

## Description
`QWIK_REDUCE_MAX` is a "Safety Floor" for the tuning process.

If your drone already flies reasonably well, you don't want a "False Positive" oscillation detection (caused by wind or a bump) to trick the system into dropping your gains to dangerously low levels. This parameter prevents Quicktune from lowering your original gains by more than the specified percentage.

*   **Default:** 20%.
*   **0:** No reduction allowed. Quicktune can only increase your gains or leave them as they are.