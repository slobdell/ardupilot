---
alias_target: RELAY1_DEFAULT
default_value: (float
description: Should the relay default to on or off, this only applies to RELAYx_FUNC
  "Relay" (1). All other uses will pick the appropriate default output state from
  within the controlling function's parameters. Note that if INVERTED is set then
  the default is inverted.
display_name: Relay default state
group: RELAY
investigation_status: alias
layout: parameter
name: RELAY6_DEFAULT
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Relay/AP_Relay_Params.cpp#L66
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Relay/AP_Relay_Params.h#L72
units: ''
visual_asset_id: null
---

# Relay default state

**Note:** This parameter functions identically to [RELAY1_DEFAULT](../RELAY/RELAY1_DEFAULT.html).
