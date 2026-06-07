---
alias_target: BATT_I2C_ADDR
default_value: HAL_BATTMON_INA2XX_ADDR
description: Battery monitor I2C address. If this is zero then probe list of supported
  addresses
display_name: Battery monitor I2C address
group: BATTE
investigation_status: alias
layout: parameter
name: BATTE_I2C_ADDR
range: 0 127
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_INA2xx.cpp#L94
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_INA2xx.h#L55
units: null
visual_asset_id: null
---

# Battery monitor I2C address

**Note:** This parameter configures Battery Monitor E. It functions identically to [BATT_I2C_ADDR](../BATT/BATT_I2C_ADDR.html).
