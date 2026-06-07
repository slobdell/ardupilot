---
layout: parameter
name: BTN_ENABLE
display_name: Enable button reporting
description: This enables the button checking module. When this is disabled the parameters for setting button inputs are not visible.
default_value: 0
range: 0 1
units: 
group: BTN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Button/AP_Button.cpp
---

# Enable button reporting (BTN_ENABLE)

## Description
Global switch to enable the button interface module. This allows physical buttons connected to the flight controller's GPIO pins to trigger auxiliary functions.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Requires reboot to make other BTN_ parameters visible in the GCS.**
