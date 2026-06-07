---
layout: parameter
name: TMODE_ACTION3
display_name: Toy Mode Action 3
description: The action taken when the third assigned button (typically Power button) is pressed.
default_value: 18
range: 0 24
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L51
---

# Toy Mode Action 3 (TMODE_ACTION3)

## Description
`TMODE_ACTION3` defines the behavior of the third utility button on the transmitter.

## Values
*   **18: Disarm (Default).** Instantly kills the motors.
*   **7: Mode RTL.** Return to home.
*   **9: Mode Land.**