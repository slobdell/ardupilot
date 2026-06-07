---
layout: parameter
name: AUTOTUNE_AXES
display_name: Autotune axis bitmask
description: Bitmap of axes to autotune.
default_value: 7
range: 
units: 
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Multi.cpp
---

# Autotune axis bitmask (AUTOTUNE_AXES)

## Description
Selects which flight axes (Roll, Pitch, Yaw) will be tested and tuned during the next AutoTune session.

## Tuning & Behavior
*   **Default Value:** 7 (Roll, Pitch, and Yaw)
*   **Bitmask:**
    *   Bit 0: Roll
    *   Bit 1: Pitch
    *   Bit 2: Yaw
*   **Tuning one axis at a time can be safer for large or unbalanced aircraft.**
