---
layout: parameter
name: TMODE_LEFT
display_name: Toy Mode Left Action
description: The action taken when the left (Mode) button is pressed (not held).
default_value: 19
range: 0 24
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L75
---

# Toy Mode Left Action (TMODE_LEFT)

## Description
`TMODE_LEFT` handles the primary "Mode" button.

*   **19: Toggle Mode (Default).** Switches between the primary modes configured in `TMODE_MODE1` and `TMODE_MODE2` (typically swapping between AltHold and Loiter).