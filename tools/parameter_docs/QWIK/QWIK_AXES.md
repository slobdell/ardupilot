---
layout: parameter
name: QWIK_AXES
display_name: Quicktune Axes
description: Bitmask of axes to be tuned by the Quicktune system.
default_value: 7
range: 0 7
units: 
group: QWIK
visual_asset_id: quicktune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L32
---

# Quicktune Axes (QWIK_AXES)

## Description
`QWIK_AXES` defines which flight axes the Quicktune assistant will attempt to optimize.

*   **Bit 0 (1):** Roll
*   **Bit 1 (2):** Pitch
*   **Bit 2 (4):** Yaw

## Tuning & Behavior
*   **Default Value:** 7 (All axes).
*   **Recommendation:** Usually, it is best to tune all three axes in one flight. However, if you are experiencing issues with a specific axis (like a vibrating tail), you can uncheck Yaw to focus only on Roll and Pitch.