---
layout: parameter
name: H_RSC_GOV_FF
display_name: Governor Feedforward
description: Feedforward governor gain to throttle response during sudden loading/unloading of the rotor system.
default_value: 50
range: 0 100
units: %
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Governor Feedforward (H_RSC_GOV_FF)

## Description
Provides an immediate throttle increase when collective pitch is increased, anticipating the load before the RPM actually drops.
