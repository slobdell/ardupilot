---
layout: parameter
name: SIM_OSD_ROWS
display_name: Simulated OSD Rows
description: The number of character rows in the simulated OSD.
default_value: 16
range: 1 30
units: 
group: SIM
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated OSD Rows (SIM_OSD_ROWS)

## Description
`SIM_OSD_ROWS` defines the height of the virtual OSD screen.

This is used for testing MSP (MultiWii Serial Protocol) OSD layouts in SITL. By changing this, you can simulate different goggle resolutions or display types.

## Tuning & Behavior
*   **Default Value:** 16 rows.
*   **Common Settings:** 13 or 16 rows for standard analog/digital systems.