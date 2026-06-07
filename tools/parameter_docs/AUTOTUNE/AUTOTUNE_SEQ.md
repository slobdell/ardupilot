---
layout: parameter
name: AUTOTUNE_SEQ
display_name: AutoTune Sequence Bitmask
description: Bitmask to select what tuning should be performed (Helicopter).
default_value: 3
range: 
units: 
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Heli.cpp
---

# AutoTune Sequence Bitmask (AUTOTUNE_SEQ)

## Description
Controls the sequence of tests performed during Helicopter AutoTune (e.g., FeedForward, Rate D/P, Angle P).

## Tuning & Behavior
*   **Default Value:** 3
*   **Bitmask:**
    *   1: VFF Only
    *   2: Rate D/Rate P Only
    *   4: Angle P Only
    *   8: Max Gain Only
    *   16: Tune Check