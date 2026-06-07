---
layout: parameter
name: BTN_SFUNCTION
display_name: "Function for button when the shift mode is toggled on"
description: "Secondary function for joystick button (Shift pressed)"
default_value: 0
range: 0 100
units: ""
group: BTN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_JSButton/AP_JSButton.cpp#L17
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_JSButton/AP_JSButton.h#L137
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Function for button when the shift mode is toggled on (BTN_SFUNCTION)

## Description
This parameter assigns a **Secondary Function** to a joystick button. This function is triggered instead of the primary `BTN_FUNCTION` when the user is simultaneously holding down the designated "Shift" button (see `BTN_OPTIONS`). This effectively doubles the number of commands available on a limited gamepad.

## The Mathematics
Logic:
$$ \text{Action} = (\text{Shift Active}) ? \text{BTN\_SFUNCTION} : \text{BTN\_FUNCTION} $$

## The Engineer's View
Defined in `libraries/AP_JSButton/AP_JSButton.cpp`.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Example:** Map Button 1 to "Mode Loiter" (primary) and "Mode RTL" (secondary/shifted).