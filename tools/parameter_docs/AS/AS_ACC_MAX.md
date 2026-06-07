---
layout: parameter
name: AS_ACC_MAX
display_name: Forward Acceleration Limit
description: Maximum forward acceleration to apply in speed controller (Autorotation).
default_value: 60
range: 30 60
units: cm/s/s
group: AS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Forward Acceleration Limit (AS_ACC_MAX)

## Description
Limits the maximum horizontal acceleration the aircraft can use to maintain forward speed during autorotation.