---
layout: parameter
name: RPM1_DC_ID
display_name: DroneCAN RPM Message ID
description: The specific DroneCAN device ID this RPM sensor instance listens for.
default_value: 0
range: 0 65535
units: 
group: RPM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RPM/AP_RPM_DroneCAN.cpp#L100
---

# DroneCAN RPM Message ID (RPM1_DC_ID)

## Description
`RPM1_DC_ID` identifies which specific piece of hardware on the DroneCAN bus is providing the RPM data for this instance.

This allows you to map multiple DroneCAN RPM sensors (e.g., from different ESCs) to specific slots in the autopilot's telemetry system.

*   **0:** Auto-detection.
*   **Value:** Specific Node ID.