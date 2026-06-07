---
layout: parameter
name: OSD_SB_H_OFS
display_name: OSD Sidebar Horizontal Offset
description: Adjusts the spacing (width) between the left and right sidebars (airspeed and altitude tapes).
default_value: 0
range: -10 10
units: 
group: OSD
visual_asset_id: osd_sidebar_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Sidebar Horizontal Offset (OSD_SB_H_OFS)

## Description
`OSD_SB_H_OFS` moves the airspeed and altitude "Ladders" closer together or further apart.

This is useful for optimizing the center of your screen for the camera view while keeping vital data visible in your peripheral vision.