---
layout: parameter
name: OSD_W_AVGCELLV
display_name: OSD Average Cell Warning
description: The average voltage per cell threshold at which the voltage display begins to flash on the OSD.
default_value: 3.6
range: 2.5 4.2
units: V
group: OSD
visual_asset_id: battery_cells_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Average Cell Warning (OSD_W_AVGCELLV)

## Description
`OSD_W_AVGCELLV` is a much better way to monitor battery life than total voltage.

Different drones use different batteries (4S, 6S, etc.). Total voltage changes, but cell voltage is universal. 

*   **3.6V (Default):** The voltage element will flash if any individual cell drops below 3.6V. This is a very safe "Land Now" voltage for LiPo batteries.

## Tuning & Behavior
*   **LiPo:** Set to **3.5V** or **3.6V**.
*   **Li-Ion:** Set to **3.0V** or **3.1V** (they can handle lower voltages safely).
*   **Requirement:** Requires [OSD_CELL_COUNT](OSD_CELL_COUNT.html) to be set correctly.