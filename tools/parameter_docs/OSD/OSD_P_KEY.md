---
layout: parameter
name: OSD_P_KEY
display_name: OSD Parameter Slot Key
description: The unique storage key for the parameter being tuned in this OSD slot.
default_value: 0
range: 0 32767
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L62
---

# OSD Parameter Slot Key (OSD_P_KEY)

## Description
`OSD_P_KEY` is a unique identifier used by ArduPilot to locate a parameter in its non-volatile memory (EEPROM). 

This is part of the triple-identifier system (Group, Key, Index) used by the OSD tuning menu to ensure that when you change a value while flying, it is saved to the correct location and persists even after the drone is powered off.

## Tuning & Behavior
*   **Setup:** This value is usually calculated and set automatically by your Ground Control Station when you choose a parameter for the OSD. You should not need to edit it manually.