---
layout: parameter
name: CAN_D1_UC_ESC_RV
display_name: DroneCAN Reversible ESC Bitmask
description: A bitmask of DroneCAN ESCs that are capable of reversible (3D) thrust.
default_value: 0
range: 0 4294967295
units: 
group: CAN
visual_asset_id: dronecan_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L138
---

# DroneCAN Reversible ESC Bitmask (CAN_D1_UC_ESC_RV)

## Description
`CAN_D1_UC_ESC_RV` identifies which CAN-based ESCs support reversing their motor direction in real-time.

*   **Standard ESC:** Only accepts 0..100% speed.
*   **Reversible ESC:** Accepts -100%..+100% speed.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set bits for all motors that need to provide reverse thrust (e.g., for 3D quads or rovers).