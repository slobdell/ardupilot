---
layout: parameter
name: BATT_HIDE_MASK
display_name: Battery hide mask
description: Instance mask of local battery index(es) to prevent transmitting their status over CAN. This is useful for hiding a "battery" instance that is used locally in the peripheral but don't want them to be treated as a battery source(s) to the autopilot.
default_value: 0
range: 
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp
---

# Battery hide mask (BATT_HIDE_MASK)

## Description
Allows an AP_Periph node to monitor multiple battery inputs internally while only reporting a subset (or a single SUM) to the primary flight controller via CAN.