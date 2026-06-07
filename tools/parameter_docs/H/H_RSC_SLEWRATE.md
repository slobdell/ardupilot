---
layout: parameter
name: H_RSC_SLEWRATE
display_name: Throttle Slew Rate
description: This controls the maximum rate at which the throttle output can change, as a percentage per second.
default_value: 0
range: 0 500
units: %/s
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Throttle Slew Rate (H_RSC_SLEWRATE)

## Description
Limits the maximum speed of throttle signal changes. This prevents sudden engine surging or mechanical strain.
*   **0: Unlimited**
*   **100: Full range in 1 second**
