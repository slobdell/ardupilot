---
layout: parameter
name: TMODE_MODE1
display_name: Toy Mode Primary Mode 1
description: The initial flight mode when the vehicle is first turned on (assumed non-GPS).
default_value: 2
range: 0 25
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L27
---

# Toy Mode Primary Mode 1 (TMODE_MODE1)

## Description
`TMODE_MODE1` sets the default flight mode that the drone starts in when powered on. In Toy Mode, this is typically a mode that does not require GPS (like `AltHold`).

## Tuning & Behavior
*   **Default Value:** 2 (AltHold).