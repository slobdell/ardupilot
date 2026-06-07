---
layout: parameter
name: ZIGZ_AUTO_ENABLE
display_name: ZigZag Auto Enable
description: Allows you to enable (1) or disable (0) the ZigZag Auto feature.
default_value: 0
range: 0 1
units: 
group: ZIGZ
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_zigzag.cpp#L18
---

# ZIGZ_AUTO_ENABLE: ZigZag Auto Enable

## Description
Allows you to enable (1) or disable (0) the ZigZag Auto feature.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Enabled |

- **Default:** 0

## Description
This parameter enables the advanced automation features of **ZigZag Mode** (Copter/Rover).

- **ZigZag Mode:** A manual/semi-auto flight mode designed for crop spraying. The pilot flies to one side of the field and flips a switch. The drone records that point as "Point A." The pilot flies to the other side and flips the switch again to record "Point B."
- **Auto Enable:** When this parameter is set to **1**, the drone will automatically fly back and forth between the two defined lines (advancing forward by the `ZIGZ_SIDE_DIST` each time), essentially creating an instant grid mission without a GCS.

