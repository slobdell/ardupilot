---
alias_target: RNGFND1_ADDR
default_value: 0
description: This sets the bus address of the sensor, where applicable. Used for the
  I2C and DroneCAN sensors to allow for multiple sensors on different addresses.
display_name: Bus address of sensor
group: RNGFND
investigation_status: alias
layout: parameter
name: RNGFND2_ADDR
range: 0 127
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L107
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.h#L31
units: ''
visual_asset_id: null
---

# Bus address of sensor

**Note:** This parameter functions identically to [RNGFND1_ADDR](../RNGFND/RNGFND1_ADDR.html).
