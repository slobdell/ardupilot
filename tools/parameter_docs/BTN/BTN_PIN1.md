---
layout: parameter
name: BTN_PIN1
display_name: First button Pin
description: Digital pin number for first button input.
default_value: -1
range: 
units: 
group: BTN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Button/AP_Button.cpp
---

# First button Pin (BTN_PIN1)

## Description
Specifies the hardware pin connected to the first physical button.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled)
*   **Common Values:** 50-55 for AUXOUT 1-6 pins.