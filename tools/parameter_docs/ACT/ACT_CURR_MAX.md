---
layout: parameter
name: ACT_CURR_MAX
display_name: Actuator Current Max (Invalid/Legacy)
description: This parameter appears to be miscategorized. It may refer to Q_TILT_MAX.
default_value: 45
range: 20 80
units: deg
group: ACT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/tiltrotor.cpp
---

# Actuator Current Max (ACT_CURR_MAX)

## Description
This parameter is not found as ACT_CURR_MAX in the main codebase. It likely refers to Q_TILT_MAX (Tiltrotor maximum VTOL angle).