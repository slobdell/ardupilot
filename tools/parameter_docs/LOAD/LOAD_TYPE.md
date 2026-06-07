---
layout: parameter
name: LOAD_TYPE
display_name: Load test type
description: This sets the type of load test pattern to run.
default_value: 1
range: 
units: 
group: LOAD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L173
---

# LOAD_TYPE: Load test type

## Description
This sets the type of load test pattern to run.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Constant Thrust |
| 1 | Log Replay 1 (Sequence) |
| 2 | Log Replay 2 (Synchronized) |

- **Default:** 1 (LogReplay1)

## Description
Selects the specific motor output pattern used during the factory load test.

- **Constant Thrust (0):** Runs all motors at a fixed, low throttle (500 PWM above min, scaled by `LOAD_MUL`).
- **Log Replay 1 (1):** Replays a pre-defined sequence of throttle values, cycling through motors.
- **Log Replay 2 (2):** Similar to Log Replay 1 but applies the pattern to all motors simultaneously.

## Source Code
[ardupilot/ArduCopter/toy_mode.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L173)

