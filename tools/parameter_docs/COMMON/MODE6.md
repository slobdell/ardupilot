---
layout: parameter
name: MODE6
display_name: "Mode6"
description: "Flight Mode for Switch Position 6"
default_value: 0
range: 0 255
units: ""
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L210
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Mode6 (MODE6)

## Description
This parameter assigns the flight/drive mode active when the RC Mode Switch is in position 6 (High, PWM > 1750us). See `MODE3`.

## The Mathematics
PWM Mapping.

## The Engineer's View
Defined in `Rover/Parameters.cpp`.

## Tuning & Behavior
*   **Default Value:** Vehicle dependent.