---
layout: parameter
name: H_RSC_THRCRV_0
display_name: Throttle Curve at 0% Collective
description: Sets the throttle output in percent for the throttle curve at the minimum collective pitch position.
default_value: 25
range: 0 100
units: %
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Throttle Curve at 0% Coll (H_RSC_THRCRV_0)

## Description
Part of a 5-point throttle curve (0, 25, 50, 75, 100). Defines the motor power required when collective pitch is at its minimum.