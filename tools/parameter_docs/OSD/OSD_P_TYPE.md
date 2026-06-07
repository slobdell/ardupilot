---
layout: parameter
name: OSD_P_TYPE
display_name: OSD Parameter Tuning Type
description: Selects the logical type of the parameter being tuned in this OSD slot.
default_value: 0
range: 0 7
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L98
---

# OSD Parameter Tuning Type (OSD_P_TYPE)

## Description
`OSD_P_TYPE` tells the OSD how to format and display the parameter assigned to this tuning slot. 

This is used to provide user-friendly names for certain common settings.

*   **0: None.** Uses the raw parameter value.
*   **1: Serial Protocol.** Displays protocol names (MAVLink, GPS, etc.).
*   **2: Servo Function.** Displays function names (Motor 1, Aileron, etc.).
*   **4: Flight Mode.**

## Tuning & Behavior
*   **Recommendation:** Set this to match the category of the parameter you are tuning to make the OSD menu easier to read while in flight.