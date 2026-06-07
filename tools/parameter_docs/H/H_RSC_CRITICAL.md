---
layout: parameter
name: H_RSC_CRITICAL
display_name: Critical Rotor Speed
description: Percentage of normal rotor speed where flight is no longer possible.
default_value: 50
range: 0 100
units: %
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Critical Rotor Speed (H_RSC_CRITICAL)

## Description
A safety threshold representing the minimum RPM required to maintain flight. If the (estimated or measured) rotor speed falls below this value, the autopilot will declare a loss of power.
*   **Commonly set so that the threshold is crossed approximately 3 seconds after a power loss.**
