---
layout: parameter
name: CAN_D1_UC_OPTION
display_name: DroneCAN Options
description: Option flags for the DroneCAN driver.
default_value: 0
range: 0 1024
units: 
group: CAN
visual_asset_id: dronecan_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L130
---

# DroneCAN Options (CAN_D1_UC_OPTION)

## Description
`CAN_D1_UC_OPTION` provides advanced configuration flags for the DroneCAN stack.

*   **1 (Bit 0):** Clear DNA Database. Force re-allocation of Node IDs on next boot.
*   **4 (Bit 2):** Enable CAN FD (Flexible Data-rate) if supported by hardware.
*   **16 (Bit 4):** Send Servo output as raw PWM (instead of normalized -1..+1).

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:**
    *   **CAN FD:** Enable this if you have CAN FD peripherals (requires H7 or G4 processor).
    *   **DNA Reset:** Set to **1** and reboot if you have duplicate Node ID errors. It will clear itself back to 0.