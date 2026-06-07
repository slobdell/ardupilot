---
layout: parameter
name: TMODE_ACTION4
display_name: Toy Mode Action 4
description: The action taken when the first action button is pressed while the Mode button is held down.
default_value: 0
range: 0 24
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L57
---

# Toy Mode Action 4 (TMODE_ACTION4)

## Description
`TMODE_ACTION4` enables a "Shift Key" functionality for the transmitter buttons. By holding down the Mode button (Left), the other buttons can perform secondary tasks.

## Values
*   **0: None (Default).**
*   **23: Motor Load Test.**
*   **15: Mode Throw.**