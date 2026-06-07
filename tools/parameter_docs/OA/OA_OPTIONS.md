---
layout: parameter
name: OA_OPTIONS
display_name: Object Avoidance Options
description: A bitmask of specialized object avoidance configuration options.
default_value: 0
range: 0 7
units: 
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OAPathPlanner.cpp#L42
---

# Object Avoidance Options (OA_OPTIONS)

## Description
`OA_OPTIONS` provides specialized toggles for the path planning system.

*   **Bit 0 (1):** Enable Logging. (Useful for developers to see why a drone chose a specific path).
*   **Bit 1 (2):** Use Proximity.
*   **Bit 2 (4):** Use Fence.