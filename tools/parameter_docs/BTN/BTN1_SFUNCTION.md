---
layout: parameter
name: BTN1_SFUNCTION
display_name: Joystick Button Shift-Function (Instance 1)
description: Assigns a secondary function to button 1, activated when a designated "Shift" button is held.
default_value: 0
range: 0 111
units: 
group: BTN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_JSButton/AP_JSButton.cpp#L17
---

# Joystick Button Shift-Function (BTN1_SFUNCTION)

## Description
`BTN1_SFUNCTION` allows you to double the number of commands available on your joystick.

If any button on your controller is assigned to **Function 1 (shift)**, then pressing this button (Button 1) while that shift button is held down will trigger the action defined here instead of the primary `BTN1_FUNCTION`.
