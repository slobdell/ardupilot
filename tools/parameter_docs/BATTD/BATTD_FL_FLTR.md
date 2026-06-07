---
alias_target: BATT_FL_FLTR
default_value: 0.3
description: Filter frequency in Hertz where a low pass filter is used. This is used
  to filter out tank slosh from the fuel level reading. A value of -1 disables the
  filter and unfiltered voltage is used to determine the fuel level. The suggested
  values at in the range of 0.2 Hz to 0.5 Hz.
display_name: Fuel level filter frequency
group: BATTD
investigation_status: alias
layout: parameter
name: BATTD_FL_FLTR
range: -1 1
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_FuelLevel_Analog.cpp#L53
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_FuelLevel_Analog.h#L52
units: Hz
visual_asset_id: null
---

# Fuel level filter frequency

**Note:** This parameter configures instance D. It functions identically to [BATT_FL_FLTR](../BATT/BATT_FL_FLTR.html).
