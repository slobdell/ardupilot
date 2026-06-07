---
layout: parameter
name: ESC_EXT_TLM_RATE
display_name: ESC Extended Telemetry update rate
description: This is the rate at which extended ESC Telemetry (duty cycle, flags, power) will be sent across the CAN bus (AP_Periph).
default_value: 5
range: 0 1000
units: Hz
group: ESC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp
---

# ESC Extended Telemetry update rate (ESC_EXT_TLM_RATE)

## Description
Controls the frequency of high-detail telemetry messages (e.g., input duty cycle, internal status flags) transmitted from the AP_Periph node via CAN.