---
layout: parameter
name: DE_PIN
display_name: Torqeedo DE pin
description: Pin number connected to RS485 to Serial converter's DE pin. -1 to use serial port's CTS pin if available.
default_value: -1
range: 
units: 
group: DE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp
---

# Torqeedo DE pin (DE_PIN)

## Description
Specifies the hardware pin used for the Data Enable (DE) signal when communicating with a Torqeedo motor via an RS485 converter.