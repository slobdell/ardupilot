---
layout: parameter
name: NTF_DISPLAY_TYPE
display_name: I2C OLED Display Type
description: Selects the driver for a small onboard OLED status display.
default_value: 0
range: 0 1
units: 
group: NTF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Notify/AP_Notify.cpp#L184
---

# I2C OLED Display Type (NTF_DISPLAY_TYPE)

## Description
`NTF_DISPLAY_TYPE` enables support for tiny onboard OLED screens (usually 128x64 or 0.96").

These screens are mounted directly to the drone and provide at-a-glance information while the drone is on the ground, such as:
*   Arming status.
*   GPS lock quality (HDOP / Sat count).
*   Battery voltage.
*   Active flight mode.

## Tuning & Behavior
*   **0: Disabled (Default).**
*   **1: SSD1306.** Standard I2C OLED driver used by most hobbyist screens.
*   **Reboot Required:** Yes.