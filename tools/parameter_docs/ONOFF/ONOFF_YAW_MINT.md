---
layout: parameter
name: ONOFF_YAW_MINT
display_name: "Yaw minimum movement time"
description: "Minimum activation time for yaw motor"
default_value: 0.1f
range: 0 2
units: "s"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L130
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Yaw minimum movement time (ONOFF_YAW_MINT)

## Description
This parameter sets the minimum duration for activating the yaw motor in an On/Off tracker system. See `ONOFF_PITCH_MINT` for details.

## The Mathematics
$$ \text{Pulse Width} = \max(\text{Calculated Time}, \text{ONOFF_YAW_MINT}) $$

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp`.

## Tuning & Behavior
*   **Default Value:** 0.1 s