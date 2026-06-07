---
layout: parameter
name: AROT_XY_ACC_MAX
display_name: Forward Acceleration Limit
description: Maximum forward acceleration to apply in speed controller.
default_value: 60
range: 30 60
units: cm/s/s
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Forward Acceleration Limit (AROT_XY_ACC_MAX)

## Description
Limits the maximum horizontal acceleration (and thus the pitch angle) the aircraft can use to maintain forward speed during autorotation glide.

## Tuning & Behavior
*   **Default Value:** 60 cm/s/s
*   **Range:** 30 to 60 cm/s/s