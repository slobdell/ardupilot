---
alias_target: BATT_AMP_PERVLT
default_value: AP_BATT_CURR_AMP_PERVOLT_DEFAULT
description: Number of amps that a 1V reading on the current sensor corresponds to.
  With a Pixhawk using the 3DR Power brick this should be set to 17. For the Pixhawk
  with the 3DR 4in1 ESC this should be 17. For Synthetic Current sensor monitors,
  this is the maximum, full throttle current draw.
display_name: Amps per volt
group: BATT
investigation_status: alias
layout: parameter
name: BATT4_AMP_PERVLT
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.cpp#L42
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.h#L126
units: A/V
visual_asset_id: null
---

# Amps per volt

**Note:** This parameter functions identically to [BATT_AMP_PERVLT](../BATT/BATT_AMP_PERVLT.html).
