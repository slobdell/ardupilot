---
layout: parameter
name: SIM_CAN_SRV_MSK
display_name: Simulated CAN Servo Mask
description: A bitmask of servo outputs that are controlled via simulated DroneCAN (AP_Periph).
default_value: 0
range: 0 4294967295
units: 
group: SIM
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L144
---

# Simulated CAN Servo Mask (SIM_CAN_SRV_MSK)

## Description
`SIM_CAN_SRV_MSK` tells the simulator which motors or servos are "Digital" (CAN).

Normally, SITL simulates servos as direct wires. If you are developing or testing DroneCAN hardware (using **AP_Periph**), you can set this mask. Any bit set to **1** will cause the simulator to expect that channel's data to come from a virtual CAN node rather than the main flight controller's internal logic.

## Tuning & Behavior
*   **0:** All servos simulated as direct internal connections.
*   **Bit 0 (1):** Servo 1 is a CAN servo.
*   **Bit 3 (8):** Servo 4 is a CAN servo.