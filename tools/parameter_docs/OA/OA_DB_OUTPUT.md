---
layout: parameter
name: OA_DB_OUTPUT
display_name: OADatabase Output Level
description: Controls which detected obstacles are sent to the Ground Control Station (GCS) for display on the map.
default_value: 1
range: 0 3
units: 
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OADatabase.cpp#L70
---

# OADatabase Output Level (OA_DB_OUTPUT)

## Description
`OA_DB_OUTPUT` determines what you see on your Mission Planner or QGC screen.

The drone always uses all known obstacles for its own avoidance, but sending every single point to the Ground Station can overwhelm the telemetry radio.

*   **0: Disabled.** No obstacles are shown on the map.
*   **1: High Importance (Default).** Only show obstacles that are very close.
*   **3: All.** Show every detected point.