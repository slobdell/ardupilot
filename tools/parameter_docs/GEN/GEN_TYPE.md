---
layout: parameter
name: GEN_TYPE
display_name: Generator type
description: Specifies the hardware type of the onboard generator or fuel cell.
default_value: 0
range: 
units: 
group: GEN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Generator/AP_Generator.cpp
---

# Generator type (GEN_TYPE)

## Description
Enables the generator control module and selects the driver for specific fuel cell or combustion generator hardware.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Values:** 0:Disabled, 1:IE 650w/800w Fuel Cell, 2:IE 2.4kW Fuel Cell, 3:RichenPower
*   **Requires reboot to take effect.**