---
layout: parameter
name: SIM_OSD_COLUMNS
display_name: Simulated OSD Columns
description: The number of character columns in the simulated OSD.
default_value: 30
range: 1 50
units: 
group: SIM
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated OSD Columns (SIM_OSD_COLUMNS)

## Description
`SIM_OSD_COLUMNS` defines the width of the virtual OSD screen.

## Tuning & Behavior
*   **Default Value:** 30 columns.