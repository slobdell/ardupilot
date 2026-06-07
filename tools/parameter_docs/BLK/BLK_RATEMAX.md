---
layout: parameter
name: BLK_RATEMAX
display_name: Block Logging Max Rate
description: Maximum rate at which data should be written to block logging (Hz). 0 means no limit.
default_value: 0
range: 
units: Hz
group: BLK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Logger/AP_Logger.cpp
---

# Block Logging Max Rate (BLK_RATEMAX)

## Description
Limits the frequency of data logging to internal flash (block storage) to conserve bandwidth and CPU.