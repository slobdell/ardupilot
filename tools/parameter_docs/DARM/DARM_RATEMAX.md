---
layout: parameter
name: DARM_RATEMAX
display_name: Disarmed Logging Max Rate
description: Maximum rate at which data should be logged when disarmed (Hz). 0 means no limit.
default_value: 0
range: 
units: Hz
group: DARM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Logger/AP_Logger.cpp
---

# Disarmed Logging Max Rate (DARM_RATEMAX)

## Description
Limits the frequency of data logging while the vehicle is disarmed. This helps conserve SD card space when the aircraft is powered on but not flying.