---
layout: parameter
name: BRD_HEAT_LOWMGN
display_name: Board heater temp lower margin
description: Arming check will fail if temp is lower than this margin below BRD_HEAT_TARG.
default_value: 0
range: 0 20
units: degC
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Board heater temp lower margin (BRD_HEAT_LOWMGN)

## Description
Safety margin for heater-based arming checks. The aircraft will refuse to arm until the IMU has reached at least (BRD_HEAT_TARG - BRD_HEAT_LOWMGN).
