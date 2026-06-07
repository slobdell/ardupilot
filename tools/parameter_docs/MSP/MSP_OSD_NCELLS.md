---
layout: parameter
name: MSP_OSD_NCELLS
display_name: MSP OSD Cell Count Override
description: Manually specifies the battery cell count for MSP OSD average cell voltage calculations.
default_value: 0
range: 0 14
units: 
group: MSP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_MSP/AP_MSP.cpp#L43
---

# MSP OSD Cell Count Override (MSP_OSD_NCELLS)

## Description
`MSP_OSD_NCELLS` allows you to manually set the cell count for the battery voltage display on digital OSDs.

While ArduPilot can usually detect cell count automatically, some digital goggles require an explicit cell count to calculate and display "Average Cell Voltage" correctly. 

*   **0:** Use global battery settings (Automatic detection).
*   **1-14:** Forces the OSD to assume a specific number of cells (e.g. 4 for a 4S battery).