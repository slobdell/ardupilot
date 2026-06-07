---
layout: parameter
name: SCR_USER1
display_name: Scripting User Parameter 1
description: A generic parameter that can be read by Lua scripts to adjust behavior without editing the script file.
default_value: 0
range: -10000 10000
units: 
group: SCR
visual_asset_id: scripting_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L44
---

# Scripting User Parameter (SCR_USER)

## Description
`SCR_USER1` through `SCR_USER6` are "Input Boxes" for your custom Lua scripts.

Instead of hard-coding values like "Speed" or "Distance" inside your script, you can write the script to look at these parameters. This allows you to change how your script behaves using your Ground Station (Mission Planner/QGC) while in the field.

## Tuning & Behavior
*   **Usage:** These parameters do nothing by themselves. Their meaning is entirely defined by the specific Lua script you are running.
