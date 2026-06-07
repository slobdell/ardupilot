---
layout: parameter
name: MODE3
display_name: "Mode3"
description: "Flight Mode for Switch Position 3"
default_value: 0
range: 0 255
units: ""
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L192
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Mode3 (MODE3)

## Description
This parameter assigns the flight/drive mode active when the RC Mode Switch (channel 5 or 8) is in its middle position (PWM ~1425us).

## The Mathematics
PWM Mapping Logic.

## The Engineer's View
Defined in `Rover/Parameters.cpp` (and other vehicle folders). Maps integer ID to mode.

## Tuning & Behavior
*   **Default Value:** Vehicle dependent.
*   **Select:** Choose from the list of available flight modes (e.g., MANUAL, ACRO, STEERING, HOLD, AUTO).