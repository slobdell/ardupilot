---
layout: parameter
name: TMODE_ACTION2
display_name: Toy Mode Action 2
description: The action taken when the second assigned button (typically Right Action) is pressed.
default_value: 1
range: 0 24
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L45
---

# Toy Mode Action 2 (TMODE_ACTION2)

## Description
`TMODE_ACTION2` maps a specific function to the secondary action button on a consumer transmitter.

## Values
*   **1:** Take Photo (Default).
*   **2:** Toggle Video.
*   **8:** Mode Circle.
*   **16:** Flip.