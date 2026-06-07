---
layout: parameter
name: H_SW_H3_ENABLE
display_name: H3 Swashplate Enable
description: Enables the specialized H3 swashplate configuration, allowing for manual positioning of the three control servos.
default_value: 0
range: 0 1
units: 
group: H
visual_asset_id: heli_swash_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Swash.cpp#L100
---

# H3 Swashplate Enable (H_SW_H3_ENABLE)

## Description
`H_SW_H3_ENABLE` activates advanced setup for 3-servo (H3) swashplates. 

Normally, ArduPilot assumes a standard 120° swashplate layout. If your helicopter has a custom mechanical layout where the servos are not at the standard positions, you enable this parameter to manually define the angle of each servo using `H_SW_H3_SV1_POS` etc.

*   **0: Default.** Use the layout selected in `H_SW_TYPE`.
*   **1: Manual.** Use custom servo angles.
