---
alias_target: BATT_AMP_OFFSET
default_value: AP_BATT_CURR_AMP_OFFSET_DEFAULT
description: Voltage offset at zero current on current sensor for Analog Sensors.
  For Synthetic Current sensor, this offset is the zero throttle system current and
  is added to the calculated throttle base current.
display_name: AMP offset
group: BATT
investigation_status: alias
layout: parameter
name: BATT5_AMP_OFFSET
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.cpp#L49
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.h#L127
units: V
visual_asset_id: null
---

# AMP offset

**Note:** This parameter functions identically to [BATT_AMP_OFFSET](../BATT/BATT_AMP_OFFSET.html).
