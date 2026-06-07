---
layout: parameter
name: EAHRS_LOG_RATE
display_name: AHRS logging rate
description: Logging rate for EARHS devices in Hz.
default_value: 10
range: 0 400
units: Hz
group: EAHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ExternalAHRS/AP_ExternalAHRS.cpp
---

# AHRS logging rate (EAHRS_LOG_RATE)

## Description
Controls how frequently the data from the external AHRS is written to the aircraft's dataflash logs (EAHR and EAHV log messages).