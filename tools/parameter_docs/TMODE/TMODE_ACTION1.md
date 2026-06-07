---
layout: parameter
name: TMODE_ACTION1
display_name: Toy Mode Action 1
description: The action taken when the first assigned button (typically Left Action) is pressed.
default_value: 2
range: 0 24
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L39
---

# Toy Mode Action 1 (TMODE_ACTION1)

## Description
`TMODE_ACTION1` maps a specific function to a button on the transmitter.

## Values
*   **1:** Take Photo.
*   **2:** Toggle Video.
*   **7:** Mode RTL.
*   **18:** Disarm.