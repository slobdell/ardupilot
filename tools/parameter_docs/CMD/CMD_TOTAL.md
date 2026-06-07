---
layout: parameter
name: CMD_TOTAL
display_name: "Number of loaded mission items"
description: "Total number of mission commands currently stored in memory"
default_value: 0
range: 0 65535
units: ""
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L511
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Number of loaded mission items (CMD_TOTAL)

## Description
This is a **Read-Only** system parameter that reports the total number of waypoint or mission commands currently uploaded to the vehicle. It is used by the Ground Control Station (GCS) to verify mission upload success and by the autopilot to know the bounds of the mission index.

## The Mathematics
N/A. Simple integer counter.

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp`. It reflects the value of `mission.num_commands()`.
*   **0:** No mission loaded (or only Home).
*   **>0:** Valid mission present.

## Tuning & Behavior
*   **Read Only:** Do not attempt to change this parameter manually. It is updated automatically when you upload a mission.