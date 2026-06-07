---
layout: parameter
name: FS_GCS_ENABLE
display_name: GCS Failsafe Enable
description: Enables or disables the Ground Control Station (GCS) telemetry link failsafe.
default_value: 0
range: 0 5
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L101
---

# GCS Failsafe Enable (FS_GCS_ENABLE)

## Description
`FS_GCS_ENABLE` defines what the drone does if it loses its MAVLink telemetry connection.

This is primarily used for long-range missions where the drone is controlled via a laptop rather than a traditional RC remote.

*   **0: Disabled (Default).** The drone continues its mission even if the telemetry link is lost.
*   **1: Enabled (RTL).** The drone returns home immediately.
*   **2: Enabled (Continue in Auto).** If the drone is currently on an autonomous mission, it continues. If not, it returns home.

## Tuning & Behavior
*   **Safety:** Ensure you have a valid Home position and no obstacles in the RTL path before enabling this.
