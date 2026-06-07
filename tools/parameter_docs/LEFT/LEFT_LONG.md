---
layout: parameter
title: LEFT_LONG
name: Tmode left long action
group: LEFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L97
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.h#L114
---

# LEFT_LONG: Tmode left long action

## Description
This is the action taken when the left (Mode) button is long-pressed in Toy Mode.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | None |
| 1 | Take Photo |
| 2 | Toggle Video |
| 3 | Mode Acro |
| 4 | Mode AltHold |
| 5 | Mode Auto |
| 6 | Mode Loiter |
| 7 | Mode RTL |
| 8 | Mode Circle |
| 9 | Mode Land |
| 10 | Mode Drift |
| 11 | Mode Sport |
| 12 | Mode AutoTune |
| 13 | Mode PosHold |
| 14 | Mode Brake |
| 15 | Mode Throw |
| 16 | Flip |
| 17 | Mode Stabilize |
| 18 | Disarm |
| 19 | Toggle Mode |
| 20 | Arm-Land-RTL |
| 21 | Toggle Simple Mode |
| 22 | Toggle Super Simple Mode |
| 23 | Motor Load Test |
| 24 | Mode FlowHold |

- **Default:** 0 (None)

## Description
This parameter assigns a specific function to the "Long Press" action of the Left Button (typically the "Mode" button) on a supported Toy Mode controller (e.g., SkyViper or similar gamepad-style controllers running ArduPilot).

## Source Code
[ardupilot/ArduCopter/toy_mode.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L97)

