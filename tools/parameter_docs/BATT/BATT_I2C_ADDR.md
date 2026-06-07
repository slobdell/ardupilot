---
layout: parameter
name: BATT_I2C_ADDR
display_name: Battery monitor I2C address
description: I2C address for smart battery.
default_value: 0
range: 0 127
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_SMBus.cpp
---

# Battery monitor I2C address (BATT_I2C_ADDR)

## Description
The I2C device address of the smart battery. A value of 0 usually triggers auto-detection.
