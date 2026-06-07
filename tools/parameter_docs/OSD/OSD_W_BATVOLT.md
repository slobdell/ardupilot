---
layout: parameter
name: OSD_W_BATVOLT
display_name: OSD Battery Voltage Warning
description: The total battery voltage at which the OSD will start flashing a warning.
default_value: 10.0
range: 0 100
units: V
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L109
---

# OSD Battery Voltage Warning (OSD_W_BATVOLT)

## Description
`OSD_W_BATVOLT` is your "Fuel Low" light.

When your battery drops to this voltage, the battery readout on your screen will flash to tell you it's time to land.

## Tuning & Behavior
*   **Recommendation:** Set this to roughly **3.4V or 3.5V per cell** for LiPo batteries. For a 4S battery, you would set this to **14.0**.
