---
layout: parameter
name: AROT_COL_FILT_G
display_name: Glide Phase Collective Filter
description: Cut-off frequency for collective low pass filter during the glide phase. Acts as a following trim. Must be lower than AROT_COL_FILT_E.
default_value: 0.1
range: 0.03 0.15
units: Hz
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Glide Phase Collective Filter (AROT_COL_FILT_G)

## Description
Low-pass filter frequency applied to collective commands during the steady-state glide phase of autorotation.

## Tuning & Behavior
*   **Default Value:** 0.1 Hz
*   **Range:** 0.03 to 0.15 Hz
*   **A lower value results in smoother collective changes during the glide.**
