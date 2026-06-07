---
alias_target: SERIAL1_BAUD
default_value: DEFAULT_SERIAL2_BAUD
description: The baud rate of the Telem2 port. Most stm32-based boards can support
  rates of up to 1500. If you setup a rate you cannot support and then can't connect
  to your board you should load a firmware from a different vehicle type. That will
  reset all your parameters to defaults.
display_name: Telemetry 2 Baud Rate
group: SERIAL
investigation_status: alias
layout: parameter
name: SERIAL2_BAUD
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_SerialManager/AP_SerialManager.cpp#L211
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_SerialManager/AP_SerialManager.h#L178
units: ''
visual_asset_id: null
---

# Telemetry 2 Baud Rate

**Note:** This parameter functions identically to [SERIAL1_BAUD](../SERIAL1/SERIAL1_BAUD.html).
