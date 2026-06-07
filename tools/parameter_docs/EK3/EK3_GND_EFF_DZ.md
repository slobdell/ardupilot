---
layout: parameter
name: EK3_GND_EFF_DZ
display_name: Baro height ground effect dead zone
description: Size of the dead zone applied to negative baro height spikes that occur when operating in ground effect.
default_value: 4.0
range: 0.0 10.0
units: m
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Baro height ground effect dead zone (EK3_GND_EFF_DZ)

## Description
Compensates for the localized high-pressure zone created under a vehicle with lift rotors during takeoff and landing. This "ground effect" can cause barometric altitude to report negative values or spikes; the dead zone ignores these fluctuations.
