---
layout: parameter
name: ESC_TELEM_RATE
display_name: ESC Telemetry update rate
description: This is the rate at which ESC Telemetry will be sent across the CAN bus.
default_value: 50
range: 0 1000
units: Hz
group: ESC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp
---

# ESC Telemetry update rate (ESC_TELEM_RATE)

## Description
Controls the frequency of telemetry messages (voltage, current, RPM) transmitted from the AP_Periph node to the main flight controller via CAN.