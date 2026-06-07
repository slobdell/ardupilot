---
layout: parameter
name: MB_CAN_PORT
display_name: Moving Baseline CAN Port option
description: Autoselect dedicated CAN port on which moving baseline data will be transmitted.
default_value: 0
range: 
units: 
group: MB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L243
---

# MB_CAN_PORT: Moving Baseline CAN Port option

## Description
Autoselect dedicated CAN port on which moving baseline data will be transmitted.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Sends moving baseline data on all ports |
| 1 | Auto select remaining port for transmitting Moving baseline Data |

- **Default:** 0

## Description
This parameter manages the routing of high-bandwidth RTK "Moving Baseline" data between two GPS units (typically for GPS-based Yaw).

- **0 (Broadcast):** The moving baseline correction data is sent out on all active CAN interfaces. This is the simplest configuration but consumes more bus bandwidth.
- **1 (Auto-Select):** The system attempts to find a specific, dedicated CAN port to send the data on, keeping the other ports free for other traffic. This is useful on devices with multiple CAN buses to segregate the heavy RTK traffic.

## Source Code
[ardupilot/Tools/AP_Periph/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L243)
