---
layout: parameter
name: H_COL_HOVER
display_name: Collective Hover Value
description: Collective needed to hover, expressed from 0 (H_COL_MIN) to 1 (H_COL_MAX).
default_value: 0.5
range: 0.3 0.8
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli.cpp
---

# Collective Hover Value (H_COL_HOVER)

## Description
The specific collective pitch setting required to maintain a stationary hover. This serves as the center-point for altitude control logic.