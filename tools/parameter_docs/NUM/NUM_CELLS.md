---
layout: parameter
title: NUM_CELLS
name: Number of battery cells
group: NUM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/batt_balance.cpp#L46
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/batt_balance.h#L13
---

# NUM_CELLS: Number of battery cells

## Description
Number of battery cells to monitor.

## Values
- **Range:** 0 to 64
- **Default:** 0

## Description
This parameter configures the **AP_Periph Battery Balancer** feature.

- **Usage:** If you have an AP_Periph device wired to monitor individual cell voltages (e.g., via analog inputs), this sets how many cells are in series.
- **Function:** The peripheral will read `NUM_CELLS` sequential analog pins starting from `CELL1_PIN`, calculate the individual cell voltages (by subtracting the previous cell's total voltage), and broadcast this data over DroneCAN.
- **0:** Disabled.

## Source Code
[ardupilot/Tools/AP_Periph/batt_balance.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/batt_balance.cpp#L46)

