---
layout: parameter
name: BATT_BAL_NUM_CELLS
display_name: Battery Balancer Cell Count
description: The total number of battery cells (in series) connected to the balancer hardware.
default_value: 0
range: 0 16
units: Cells
group: BATT
visual_asset_id: battery_cells_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattBalance.cpp
---

# Battery Balancer Cell Count (BATT_BAL_NUM_CELLS)

## Description
`BATT_BAL_NUM_CELLS` defines the configuration of your battery pack for the internal balancing system.

This is only used if you have specialized hardware (like a dedicated balancer board) that allows the flight controller to monitor or equalize individual cell voltages.

*   **Default:** 0.
*   **Usage:** Set to the number of cells in series (e.g. 4 for 4S, 6 for 6S).