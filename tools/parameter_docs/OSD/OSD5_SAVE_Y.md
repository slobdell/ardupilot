---
layout: parameter
name: OSD5_SAVE_Y
display_name: "SAVE_Y"
description: "Vertical position of Save button on OSD screen"
default_value: 11
range: 0 15
units: ""
group: OSD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_ParamScreen.cpp#L109
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# SAVE_Y (OSD5_SAVE_Y)

## Description
This parameter defines the row number (Y-coordinate) for the "SAVE" button on the OSD Parameter Tuning page (Screen 5).

## The Mathematics
Grid coordinates (0-15 rows).

## The Engineer's View
Defined in `libraries/AP_OSD/AP_OSD_ParamScreen.cpp`.

## Tuning & Behavior
*   **Default Value:** 11
*   **Usage:** Move the button if it overlaps with other OSD elements.