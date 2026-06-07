---
layout: parameter
name: DOCK_HDG_CORR_WT
display_name: Dock Heading Correction Weight
description: Controls how aggressively the vehicle prioritizes heading alignment versus direct distance during the docking approach.
default_value: 0.75
range: 0 1.0
units: 
group: DOCK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/mode_dock.cpp#L36
---

# Dock Heading Correction Weight (DOCK_HDG_CORR_WT)

## Description
`DOCK_HDG_CORR_WT` fine-tunes the geometry of the docking path.