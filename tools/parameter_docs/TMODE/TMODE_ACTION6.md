---
layout: parameter
name: TMODE_ACTION6
display_name: Toy Mode Action 6
description: The action taken when the power button is pressed while the Mode button is held down.
default_value: 0
range: 0 24
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L69
---

# Toy Mode Action 6 (TMODE_ACTION6)

## Description
`TMODE_ACTION6` maps a secondary function to the power button while in the "Shifted" state.