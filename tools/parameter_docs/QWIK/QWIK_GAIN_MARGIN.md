---
layout: parameter
name: QWIK_GAIN_MARGIN
display_name: Quicktune Gain Margin
description: The percentage reduction in gain applied after an oscillation is detected.
default_value: 60
range: 20 80
units: %
group: QWIK
visual_asset_id: quicktune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L46
---

# Quicktune Gain Margin (QWIK_GAIN_MARGIN)

## Description
`QWIK_GAIN_MARGIN` determines how "Conservative" or "Aggressive" the final tune will be.

During the tuning process, Quicktune increases your gains until the drone starts to shake (oscillate). It then takes that "Limit" value and reduces it by this percentage to find a safe, stable flying gain.

*   **Higher Value (80%):** More conservative. The final gains will be lower and the drone will feel smoother but less "Locked in."
*   **Lower Value (40%):** More aggressive. The final gains will be closer to the oscillation point, resulting in a very sharp, high-performance feel.

## Tuning & Behavior
*   **Default Value:** 60%.
*   **Recommendation:** Start with **60%**. If the drone still feels a bit loose after tuning, try **50%**.