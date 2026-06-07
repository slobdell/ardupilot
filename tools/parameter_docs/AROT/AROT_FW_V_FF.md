---
layout: parameter
name: AROT_FW_V_FF
display_name: Velocity (horizontal) feed forward
description: Velocity (horizontal) input filter. Corrects the target acceleration proportionally to the desired velocity.
default_value: 0.15
range: 0 1
units: 
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Velocity (horizontal) feed forward (AROT_FW_V_FF)

## Description
Feed-forward gain for the horizontal velocity controller.

## Tuning & Behavior
*   **Default Value:** 0.15
*   **Range:** 0 to 1