---
layout: parameter
name: CELL_COUNT
display_name: OSD Battery Cell Count
description: Number of cells in the battery for OSD voltage display. A value of -1 means to auto-detect.
default_value: -1
range: -1 12
units: 
group: CELL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD.cpp
---

# OSD Battery Cell Count (CELL_COUNT)

## Description
Configures the battery cell count used by the On-Screen Display to calculate per-cell voltage. 
*   **-1 (default) enables auto-detection based on total voltage at boot.**