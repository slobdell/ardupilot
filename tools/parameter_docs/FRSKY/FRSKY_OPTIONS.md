---
layout: parameter
name: FRSKY_OPTIONS
display_name: FRSky Telemetry Options
description: Bitmask of options for the FRSky telemetry system.
default_value: 0
range: 
units: 
group: FRSKY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Frsky_Telem/AP_Frsky_Parameters.cpp
---

# FRSky Telemetry Options (FRSKY_OPTIONS)

## Description
Configuration bitmask for tailoring the FrSky telemetry output.
*   **Bit 0: EnableAirspeedAndGroundspeed (Force both to be sent)**