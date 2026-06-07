---
layout: parameter
name: SIMPLE_TYPE
display_name: Simple mode types
description: Simple mode types.
default_value: 0
range: 0 1
units: 
group: SIMPLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L562
---

# SIMPLE_TYPE: Simple mode types

## Description
This parameter selects the behavior of "Simple Mode" on a Rover.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Initial Heading (Stick forward matches vehicle's orientation at arming) |
| 1 | Home Direction (Stick forward always moves the vehicle away from home) |

- **Default:** 0 (Initial Heading)

## Description
**Simple Mode** changes how the steering stick works to make it easier for beginners to fly/drive when the vehicle is facing them.

- **Initial Heading (0):** The autopilot remembers which way the rover was facing when it armed. If you push the stick forward, it always tries to drive in that direction, regardless of which way the nose is currently pointed.
- **Home Direction (1):** "Super Simple" mode. If you push the stick away from you, the rover always drives away from its home point. If you pull the stick back, it always drives towards home. This is perfect if you lose orientation.
- **Requirement:** Requires a good Compass and GPS lock to function correctly.

