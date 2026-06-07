---
layout: parameter
name: Q_AUTOTUNE_AXES
display_name: QuadPlane Autotune Axes
description: A bitmask selecting which axes (Roll, Pitch, Yaw) are tuned during the QAUTOTUNE mode.
default_value: 7
range: 1 7
units: 
group: Q
visual_asset_id: autotune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Autotune Axes (Q_AUTOTUNE_AXES)

## Description
`Q_AUTOTUNE_AXES` selects which parts of the drone the Autotuner will wiggle and measure.

*   **Bit 0 (1):** Roll
*   **Bit 1 (2):** Pitch
*   **Bit 2 (4):** Yaw

## Tuning & Behavior
*   **Default Value:** 7 (All Axes).
*   **Recommendation:** If you have a fragile airframe or limited battery, tune one axis at a time.
    *   Set to **1** (Roll only), fly, land, save.
    *   Set to **2** (Pitch only), fly, land, save.
    *   Set to **4** (Yaw only), fly, land, save.