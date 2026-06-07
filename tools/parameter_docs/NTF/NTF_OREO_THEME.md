---
layout: parameter
name: NTF_OREO_THEME
display_name: OreoLED Theme Selection
description: Selects the color and animation pattern for OreoLED status lights (e.g. 3DR Solo).
default_value: 0
range: 0 2
units: 
group: NTF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Notify/AP_Notify.cpp#L193
---

# OreoLED Theme Selection (NTF_OREO_THEME)

## Description
`NTF_OREO_THEME` enables the specialized status light driver for **OreoLED** hardware (found on the 3DR Solo and some companion peripherals).

*   **0: Disabled (Default).**
*   **1: Aircraft Theme.** Uses standard aviation colors (Red/Green/White) to indicate orientation and system status.
*   **2: Rover Theme.** Uses specialized patterns for ground vehicles.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Only enable this if you have physical OreoLED hardware connected to the I2C bus.