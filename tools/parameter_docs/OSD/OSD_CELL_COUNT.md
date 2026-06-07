---
layout: parameter
name: OSD_CELL_COUNT
display_name: OSD Battery Cell Count
description: The number of cells in the battery pack. Used to calculate average cell voltage warnings.
default_value: -1
range: -1 14
units: 
group: OSD
visual_asset_id: battery_cells_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Battery Cell Count (OSD_CELL_COUNT)

## Description
`OSD_CELL_COUNT` tells the OSD how many cells are in your battery.

This is critical for the "Average Cell Voltage" display and warning. If you set this incorrectly, the OSD will report the wrong voltage per cell and might flash "Low Battery" warnings when the battery is actually full.

*   **-1 (Default):** Auto-detect based on voltage at boot. (Assumes you plug in a fully charged battery).
*   **1-14:** Manually specify the cell count (e.g. 4 for a 4S pack).

## Tuning & Behavior
*   **Recommendation:** If you sometimes fly with partially discharged batteries, **manually set this value** to your battery's cell count to avoid detection errors.