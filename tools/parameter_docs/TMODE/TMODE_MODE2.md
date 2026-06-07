---
layout: parameter
name: TMODE_MODE2
display_name: Toy Mode Primary Mode 2
description: The secondary flight mode (assumed GPS-required).
default_value: 5
range: 0 25
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L33
---

# Toy Mode Primary Mode 2 (TMODE_MODE2)

## Description
`TMODE_MODE2` is the "Advanced" mode for Toy Mode drones, typically requiring a GPS fix (like `Loiter`).