---
layout: parameter
name: MODE5
display_name: "Mode5"
description: "Flight Mode for Switch Position 5"
default_value: 0
range: 0 255
units: ""
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L204
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Mode5 (MODE5)

## Description
This parameter assigns the flight/drive mode active when the RC Mode Switch is in position 5 (PWM ~1685us). See `MODE3`.

## The Mathematics
PWM Mapping.

## The Engineer's View
Defined in `Rover/Parameters.cpp`.

## Tuning & Behavior
*   **Default Value:** Vehicle dependent.