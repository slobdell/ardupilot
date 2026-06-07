---
alias_target: RNGFND1_ADDR
default_value: 0
description: This sets the bus address of the sensor, where applicable. Used for the
  I2C and DroneCAN sensors to allow for multiple sensors on different addresses.
display_name: Bus address of sensor
group: RNGFNDA
investigation_status: alias
layout: parameter
name: RNGFNDA_ADDR
range: 0 127
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L107
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.h#L31
units: null
visual_asset_id: null
---

# Bus address of sensor

**Note:** This parameter configures instance A. It functions identically to [RNGFND1_ADDR](../RNGFND1/RNGFND1_ADDR.html).
