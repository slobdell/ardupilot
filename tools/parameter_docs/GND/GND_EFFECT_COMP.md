---
layout: parameter
name: GND_EFFECT_COMP
display_name: Ground Effect Compensation Enable/Disable
description: Enables or disables the ground effect compensation feature.
default_value: 1
range: 0 1
units: 
group: GND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L772
---

# GND_EFFECT_COMP: Ground Effect Compensation Enable/Disable

## Description
Enables or disables the ground effect compensation feature.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Enabled |

- **Default:** 1

## Description
This parameter activates the **Ground Effect Compensation** logic for multicopters.

- **Phenomenon:** When a drone flies close to the ground (usually within one rotor diameter), the air pressure builds up underneath it ("Ground Effect"), increasing lift. This can cause the drone to "float" or become jumpy during landing.
- **Function:** The autopilot detects when it is entering ground effect (based on barometer and throttle/climb rate mismatch) and automatically reduces the target throttle to maintain a smooth descent.
- **Benefit:** Smoother landings and reduced tendency to bounce or balloon upon touchdown.

