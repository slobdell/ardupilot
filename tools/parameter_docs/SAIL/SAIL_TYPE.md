---
layout: parameter
name: SAIL_TYPE
display_name: Sailboat simulation sail type
description: '0: mainsail with sheet, 1: directly actuated wing'
default_value: 0
range: 0 1
units: 
group: SAIL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1250
---

# SAIL_TYPE: Sailboat simulation sail type

## Description
This parameter selects the mechanical configuration of the sail for the SITL (Software-In-The-Loop) sailboat simulation.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Mainsail with Sheet (Conventional cloth sail) |
| 1 | Directly Actuated Wing (Rigid wing sail) |

- **Default:** 0 (Mainsail)

## Description
`SAIL_TYPE` tells the simulator which physics model to use for the sailboat's propulsion.

- **Mainsail (0):** Simulates a flexible sail controlled by a winch (sheet). The sail billows and generates lift based on the tension of the sheet and wind angle.
- **Wing (1):** Simulates a rigid wing (similar to those on high-performance racing catamarans) that is directly rotated to a specific angle of attack by a servo.
