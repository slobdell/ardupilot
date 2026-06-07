---
layout: parameter
name: SERVO_FN
display_name: Torqeedo Servo Output Function
description: Torqeedo Servo Output Function.
default_value: 70
range: 70 74
units: 
group: SERVO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp#L71
---

# SERVO_FN: Torqeedo Servo Output Function

## Description
Torqeedo Servo Output Function.

## Values
| Value | Meaning |
| :--- | :--- |
| 70 | Throttle |
| 73 | Throttle Left |
| 74 | Throttle Right |

- **Default:** 70 (Throttle)

## Description
This parameter is part of the **Torqeedo** interface (for electric boat motors).

- **Function:** It tells the Torqeedo backend which virtual "servo channel" output from the flight controller should be used to command the motor's power.
- **Normal Usage:** In a single-motor boat, this is set to **70 (Throttle)**. 
- **Skid Steering:** In a dual-motor boat, one motor's backend might be set to **73 (Throttle Left)** and the other to **74 (Throttle Right)**.
