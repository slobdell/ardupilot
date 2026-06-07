---
layout: parameter
name: OSD_ARM_SCR
display_name: OSD Arm Screen
description: Selects which OSD screen is shown when the vehicle is armed.
default_value: 0
range: 0 4
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Arm Screen (OSD_ARM_SCR)

## Description
`OSD_ARM_SCR` automatically switches your OSD view when you arm the drone.

Many pilots like to have a clean screen for setup but want full telemetry (Home distance, speed, time) as soon as they start flying.

*   **0:** No change (Stay on current screen).
*   **1-4:** Switch to Screen 1, 2, 3, or 4.