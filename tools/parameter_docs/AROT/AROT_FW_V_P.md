---
layout: parameter
name: AROT_FW_V_P
display_name: Velocity (horizontal) P gain
description: Velocity (horizontal) P gain. Determines the proportion of the target acceleration based on the velocity error.
default_value: 0.9
range: 0.1 6.0
units: 
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Velocity (horizontal) P gain (AROT_FW_V_P)

## Description
Proportional gain for the horizontal velocity controller during autorotation glide.

## Tuning & Behavior
*   **Default Value:** 0.9
*   **Range:** 0.1 to 6.0
*   **Controls how aggressively the aircraft maintains its target forward speed during descent.**