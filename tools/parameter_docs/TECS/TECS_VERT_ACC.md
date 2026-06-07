---
layout: parameter
name: TECS_VERT_ACC
display_name: Vertical Acceleration Limit
description: The maximum allowed vertical acceleration (in m/s/s) the autopilot will demand.
default_value: 7.0
range: 1.0 10.0
units: m/s/s
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L105
---

# Vertical Acceleration Limit (TECS_VERT_ACC)

## Description
`TECS_VERT_ACC` defines the "G-Limit" for vertical maneuvers.

When the drone needs to climb or descend suddenly, it will limit the force of the pull-up or push-down to this value. This protects the wings from structural damage and prevents the EKF from being overwhelmed by high G-loads.

*   **7.0 (Default):** Standard for most planes.
*   **10.0:** For high-performance, stiff airframes.