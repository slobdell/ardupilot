---
layout: parameter
name: MOT_BOOST_SCALE
display_name: Booster Motor Scale Factor
description: Sets the power ratio between the main lift motors and a dedicated booster (thrust) motor.
default_value: 0
range: 0 5.0
units: 
group: MOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L180
---

# Booster Motor Scale Factor (MOT_BOOST_SCALE)

## Description
`MOT_BOOST_SCALE` is used for hybrid aircraft that have dedicated "Thrust" motors in addition to their lift motors (e.g. some Tailsitters or QuadPlanes).

It defines how much the booster motor responds when you push the throttle. The booster motor's output is calculated as:
$$ \text{Booster Output} = \text{Main Throttle} \times \text{MOT\_BOOST\_SCALE} $$

*   **0:** Disabled.
*   **1.0:** The booster motor mirrors the throttle exactly.
*   **> 1.0:** The booster motor provides more power than the main lift motors at the same stick position.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Use this to balance your forward-flight speed against your climb-rate performance.