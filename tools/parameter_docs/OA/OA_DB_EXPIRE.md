---
layout: parameter
name: OA_DB_EXPIRE
display_name: OADatabase Item Timeout
description: The time (in seconds) an obstacle stays in the database without being re-detected before it is deleted.
default_value: 10
range: 0 127
units: s
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OADatabase.cpp#L48
---

# OADatabase Item Timeout (OA_DB_EXPIRE)

## Description
`OA_DB_EXPIRE` controls the "Forgetting Speed" of the drone.

In a dynamic environment (like people walking around), you want the drone to forget old obstacle locations quickly. In a static environment (like a building site), you want it to remember them longer.

*   **0:** Never forget. Useful for pre-loaded static maps.
*   **10 (Default):** Standard for mixed environments.