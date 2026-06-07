---
layout: parameter
name: RATE_ENABLE
display_name: Yaw rate enable
description: Enable yaw rate controller for aerobatic flight.
default_value: 0
range: 
units: 
group: RATE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_YawController.cpp#L80
---

# RATE_ENABLE: Yaw rate enable

## Description
Enable yaw rate controller for aerobatic flight.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Enabled |

- **Default:** 0

## Description
This parameter enables a dedicated rate-based controller for the Yaw axis on fixed-wing aircraft.

- **Function:** When enabled, the autopilot will try to maintain a specific yaw rate (degrees per second) proportional to the rudder stick input, rather than just passing the stick input directly to the servo.
- **Use Case:** Primarily for aerobatic planes or 3D flight where precise yaw rate control is desired during maneuvers like knife-edge or spins. For standard coordinated turns, the standard lateral acceleration controller is usually sufficient.

