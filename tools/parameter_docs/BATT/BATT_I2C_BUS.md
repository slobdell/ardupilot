---
layout: parameter
name: BATT_I2C_BUS
display_name: Battery monitor I2C bus
description: I2C bus number for smart battery.
default_value: 0
range: 0 3
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_SMBus.cpp
---

# Battery monitor I2C bus (BATT_I2C_BUS)

## Description
Specifies the physical I2C bus where the smart battery (SMBus/I2C) is connected.
