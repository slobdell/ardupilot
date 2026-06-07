---
layout: parameter
name: BRD_SAFETY_MASK
display_name: Outputs which ignore the safety switch state
description: A bitmask which controls what outputs can move while the safety switch has not been pressed.
default_value: 0
range: 
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Outputs which ignore the safety switch state (BRD_SAFETY_MASK)

## Description
Allows specific servo/motor outputs to function even if the hardware safety switch is in the "Safe" position. Commonly used for non-propulsion servos like camera gimbals or retractable landing gear.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask corresponds to output channels 1 through 14.**