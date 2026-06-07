---
layout: parameter
name: BRD_SD_SLOWDOWN
display_name: microSD slowdown
description: Scaling factor to slow down microSD operation for improved reliability on certain cards.
default_value: 0
range: 0 32
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# microSD slowdown (BRD_SD_SLOWDOWN)

## Description
Reduces the SPI bus speed for the microSD card. This can resolve "No SD Card" or logging errors on certain combinations of flight boards and card types.