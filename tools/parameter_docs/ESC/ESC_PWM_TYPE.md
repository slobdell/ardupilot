---
layout: parameter
name: ESC_PWM_TYPE
display_name: Output PWM type
description: This selects the output PWM type, allowing for normal PWM continuous output, OneShot, brushed or DShot motor output.
default_value: 0
range: 
units: 
group: ESC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp
---

# Output PWM type (ESC_PWM_TYPE)

## Description
Configures the motor output protocol for the AP_Periph node.

## Tuning & Behavior
*   **Default Value:** 0 (Normal PWM)
*   **Values:** 1:Normal, 2:OneShot, 3:OneShot125, 4:Brushed, 5:DShot150, 6:DShot300, 7:DShot600, 8:DShot1200