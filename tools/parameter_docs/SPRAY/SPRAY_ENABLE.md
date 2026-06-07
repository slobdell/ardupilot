---
layout: parameter
name: SPRAY_ENABLE
display_name: Sprayer enable/disable
description: Allows you to enable (1) or disable (0) the sprayer.
default_value: 0
range: 0 1
units: 
group: SPRAY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Sprayer/AC_Sprayer.cpp#L23
---

# SPRAY_ENABLE: Sprayer enable/disable

## Description
This parameter enables or disables the automatic crop sprayer functionality.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Enabled |

- **Default:** 0

## Description
The **Sprayer** module is designed for agricultural drones. It automatically controls a pump and a spinner based on the aircraft's ground speed and position.

- **Function:** When enabled, the autopilot will calculate the required pump speed (`SPRAY_PUMP_RATE`) to ensure an even distribution of liquid regardless of how fast the drone is flying.
- **Automation:** It can be configured to start and stop automatically when the drone enters or leaves a designated spray area in a mission.
- **Hardware:** Requires a servo or ESC-controlled pump assigned to `SERVOx_FUNCTION = 94` (SprayerPump) and optionally a spinner on `SERVOx_FUNCTION = 95` (SprayerSpinner).
