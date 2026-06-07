---
layout: parameter
name: AROT_COL_FILT_E
display_name: Entry Phase Collective Filter
description: Cut-off frequency for collective low pass filter during the entry phase. Acts as a following trim. Must be higher than AROT_COL_FILT_G.
default_value: 0.7
range: 0.2 0.5
units: Hz
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Entry Phase Collective Filter (AROT_COL_FILT_E)

## Description
Low-pass filter frequency applied to collective commands during the initial entry into autorotation.

## Tuning & Behavior
*   **Default Value:** 0.7 Hz
*   **Range:** 0.2 to 0.5 Hz (Note: Default in code is 0.7, range documentation says 0.2-0.5)
*   **Controls the reactivity of the collective during the critical transition to autorotation.**
