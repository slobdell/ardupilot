---
layout: parameter
name: BRD_BOOT_DELAY
display_name: Boot delay
description: Adds a delay in milliseconds to boot to ensure peripherals initialise fully.
default_value: 0
range: 0 10000
units: ms
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Boot delay (BRD_BOOT_DELAY)

## Description
Delays the main autopilot initialization process on startup. This is helpful if certain external sensors or peripherals (like some GPS modules) need more time to power up before ArduPilot attempts to communicate with them.
