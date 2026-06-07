---
layout: parameter
name: H_RSC_GOV_TORQUE
display_name: Governor Torque Limiter
description: Adjusts the engine's percentage of torque rise on autothrottle during ramp-up to governor speed.
default_value: 30
range: 10 60
units: %
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Governor Torque Limiter (H_RSC_GOV_TORQUE)

## Description
Limits how quickly the engine can increase torque during the initial transition to governor control, ensuring a smooth engagement of the AutoThrottle.
