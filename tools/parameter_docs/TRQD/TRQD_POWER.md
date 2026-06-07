---
layout: parameter
name: TRQD_POWER
display_name: Torqeedo Motor Power Limit
description: Sets the maximum allowed power output (as a percentage) for the Torqeedo motor.
default_value: 100
range: 0 100
units: %
group: TRQD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp#L45
---

# Torqeedo Motor Power Limit (TRQD_POWER)

## Description
`TRQD_POWER` allows you to cap the maximum output of a Torqeedo electric boat motor.

Since Torqeedo motors are very powerful, you may want to limit the maximum energy consumption to extend your mission time or to prevent the motor from overwhelming a small hull. This parameter scales the autopilot's full-throttle request to this percentage of the motor's actual capability.

## Tuning & Behavior
*   **Default:** 100%.
*   **Usage:** Set to **50** or **75** to improve energy efficiency for long-range autonomous boating.
*   **Dependency:** Only active if [TRQD_TYPE](TRQD_TYPE.html) is set to a motor driver mode.