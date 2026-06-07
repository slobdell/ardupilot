---
layout: parameter
name: RCIN_MSGRATE
display_name: RC Input Message Rate
description: The frequency (in Hz) at which RC input status messages are broadcast over the internal bus.
default_value: 10
range: 1 100
units: Hz
group: RCIN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/rc_in.cpp
---

# RC Input Message Rate (RCIN_MSGRATE)

## Description
`RCIN_MSGRATE` defines the "Update Speed" for radio control signals within the system.