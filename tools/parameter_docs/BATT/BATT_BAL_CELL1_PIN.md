---
layout: parameter
name: BATT_BAL_CELL1_PIN
display_name: Battery Balance Cell 1 Pin
description: The analog input pin number for the first cell in a multi-cell battery balancer harness.
default_value: -1
range: -1 127
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/batt_balance.cpp#L64
---

# Battery Balance Cell 1 Pin (BATT_BAL_CELL1_PIN)

## Description
`BATT_BAL_CELL1_PIN` is used by specialized battery monitoring hardware to track the voltage of individual cells in a LiPo pack.

Instead of just seeing the "Total" voltage of the battery, this parameter (and the pins that follow it) allows the autopilot to monitor each cell. This is critical for detecting a single bad cell that might be failing even if the total voltage looks acceptable.

## Tuning & Behavior
*   **Hardware:** This requires a dedicated "Cell Balancer" circuit or a custom wiring harness connected to several analog pins on the flight controller.
*   **Sequential Logic:** You only define the pin for **Cell 1**. The software automatically assumes that Cell 2 is on the next physical pin, Cell 3 on the next, and so on.