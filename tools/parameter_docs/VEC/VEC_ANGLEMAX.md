---
layout: parameter
name: VEC_ANGLEMAX
display_name: Vector thrust angle max
description: The angle between steering's middle position and maximum position when using vectored thrust (boats only).
default_value: 0.0
range: 0 90
units: deg
group: VEC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AR_Motors/AP_MotorsUGV.cpp#L112
---

# VEC_ANGLEMAX: Vector thrust angle max

## Description
The angle between steering's middle position and maximum position when using vectored thrust (boats only).

## Values
- **Range:** 0 to 90
- **Units:** deg
- **Default:** 0.0

## Description
This parameter is used for boats equipped with **Vectored Thrust** (e.g., an outboard motor or an airboat with rudders behind the prop).

- **Function:** It tells the autopilot the physical range of motion of the steering mechanism.
- **Usage:** If your outboard motor can turn 30 degrees left and 30 degrees right, set this parameter to **30**.
- **Effect:** The autopilot uses this angle to calculate the correct mixing between thrust and steering force. If set to 0, vectored thrust mixing is disabled.
