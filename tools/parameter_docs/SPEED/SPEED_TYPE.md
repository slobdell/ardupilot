---
layout: parameter
name: SPEED_TYPE
display_name: Wind speed sensor Type
description: Wind speed sensor type.
default_value: 0
range: 0 4
units: 
group: SPEED
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_WindVane/AP_WindVane.cpp#L122
---

# SPEED_TYPE: Wind speed sensor Type

## Description
This parameter selects the type of hardware used to measure wind speed (anemometer) when using the WindVane library.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | None (Disabled) |
| 1 | Analog Pin (Voltage-based anemometer) |
| 2 | Modern Device (I2C or Serial sensor) |
| 4 | SITL (Simulation only) |

- **Default:** 0

## Description
`SPEED_TYPE` is used on autonomous sailboats and wind-monitoring systems to quantify the current wind velocity.

- **Function:** Knowing the exact wind speed allows the autopilot to make better decisions about sail trim and tacking maneuvers. 
- **Requirement:** Once you select a type, you must also configure the corresponding hardware pins (e.g., `WNDVN_SPEED_PIN`) and scaling factors.
- **Usage:** Primarily used in **ArduRover** (Sailboat) and specialized ground stations.
