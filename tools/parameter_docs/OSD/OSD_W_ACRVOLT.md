---
layout: parameter
name: OSD_W_ACRVOLT
display_name: OSD Avg Cell Resting Voltage Warning
description: The estimated average resting cell voltage at which the OSD will start flashing a warning.
default_value: 3.6
range: 0 100
units: V
group: OSD
visual_asset_id: battery_cells_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD.cpp#L215
---

# OSD Avg Cell Resting Voltage Warning (OSD_W_ACRVOLT)

## Description
`OSD_W_ACRVOLT` combines two of ArduPilot's smartest battery monitoring features: **Average Cell Voltage** and **Resting Voltage Estimation**.

It monitors the estimated resting voltage divided by the number of cells. This is the ultimate "True Energy" gauge. It tells you the state of the battery without the confusion of voltage sag or varying cell counts. When this value drops below the threshold, the cell voltage element on your OSD will flash.

## Tuning & Behavior
*   **Default:** 3.6V.
*   **Recommendation:** Set to **3.5V** or **3.6V** for LiPo. This provides a very consistent warning regardless of whether you are hovering or performing a full-throttle climb.
*   **Prerequisite:** Requires [OSD_CELL_COUNT](OSD_CELL_COUNT.html) to be set correctly.