---
layout: parameter
title: RELAY_ON
name: Camera relay ON value
group: RELAY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Camera/AP_Camera_Params.cpp#L52
---

# RELAY_ON: Camera relay ON value

## Description
This sets whether the relay goes high or low when it triggers. Note that you should also set `RELAY_DEFAULT` appropriately for your camera.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Low (Ground) |
| 1 | High (3.3V or 5V) |

- **Default:** 1

## Description
This parameter configures the electrical signal logic used to trigger a camera via a relay.

- **Usage:** Set this to match your camera's shutter release requirement. Most cameras trigger on a transition.
- **Function:** When the "Take Photo" command is issued, the assigned relay pin will switch to the level defined here for the duration set in `CAM_DURATION`.

## Source Code
[ardupilot/libraries/AP_Camera/AP_Camera_Params.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Camera/AP_Camera_Params.cpp#L52)

