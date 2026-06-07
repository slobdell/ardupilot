---
layout: parameter
name: OSD5_SAVE_X
display_name: "SAVE_X"
description: "Horizontal position of Save button on OSD screen"
default_value: 23
range: 0 25
units: ""
group: OSD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_ParamScreen.cpp#L102
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# SAVE_X (OSD5_SAVE_X)

## Description
This parameter defines the column number (X-coordinate) for the "SAVE" button on the OSD Parameter Tuning page (Screen 5).

## The Mathematics
Grid coordinates (0-29 columns typically).

## The Engineer's View
Defined in `libraries/AP_OSD/AP_OSD_ParamScreen.cpp`.

## Tuning & Behavior
*   **Default Value:** 23