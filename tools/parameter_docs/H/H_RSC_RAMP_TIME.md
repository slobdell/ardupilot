---
layout: parameter
name: H_RSC_RAMP_TIME
display_name: Throttle Ramp Time
description: Time in seconds for throttle output to ramp from idle to the flight setpoint.
default_value: 1
range: 0 60
units: s
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Throttle Ramp Time (H_RSC_RAMP_TIME)

## Description
Controls how quickly the throttle signal increases when starting the motor. A slower ramp prevents sudden torque spikes that could damage the gears or drive belts.
