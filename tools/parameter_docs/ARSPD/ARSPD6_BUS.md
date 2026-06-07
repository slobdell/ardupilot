---
alias_target: ARSPD_BUS
default_value: 1
description: Bus number of the I2C bus where the airspeed sensor is connected. May
  not correspond to board's I2C bus number labels. Retry another bus and reboot if
  airspeed sensor fails to initialize.
display_name: Airspeed I2C bus
group: ARSPD
investigation_status: alias
layout: parameter
name: ARSPD6_BUS
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp#L122
units: ''
visual_asset_id: null
---

# Airspeed I2C bus

**Note:** This parameter functions identically to [ARSPD_BUS](../ARSPD/ARSPD_BUS.html).
