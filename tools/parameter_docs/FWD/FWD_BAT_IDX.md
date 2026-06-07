---
layout: parameter
name: FWD_BAT_IDX
display_name: Forward Battery Index
description: The battery monitor instance index (1-indexed) used for forward thrust voltage compensation.
default_value: 0
range: 0 10
units: 
group: FWD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Forward Battery Index (FWD_BAT_IDX)

## Description
Selects which battery monitor instance is physically connected to the forward propulsion battery (if different from the vertical lift battery).