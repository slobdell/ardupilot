---
layout: parameter
name: SW_METHOD
display_name: Screen switch method
description: This sets the method used to switch different OSD screens.
default_value: 0
range: 0 2
units: 
group: SW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L83
---

# SW_METHOD: Screen switch method

## Description
This sets the method used to switch different OSD screens.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Toggle (Click to cycle through screens) |
| 1 | PWM Range (Switch selects screen based on PWM band) |
| 2 | Auto Switch (Switch screens automatically at a set interval) |

- **Default:** 0

## Description
This parameter (`OSD_SW_METHOD`) configures how the pilot changes between the multiple OSD layouts (Screen 1, Screen 2, etc.) using the RC channel assigned to `OSD_SW_CHAN`.

- **Toggle (0):** Each time you flip the switch High and back to Low, the OSD cycles to the next screen. Good for momentary switches.
- **PWM Range (1):** The position of a 3-position or rotary switch directly selects the screen. Low = Screen 1, Mid = Screen 2, High = Screen 3. Best for 3-pos switches.
- **Auto Switch (2):** The screens cycle automatically every few seconds. Not commonly used.

