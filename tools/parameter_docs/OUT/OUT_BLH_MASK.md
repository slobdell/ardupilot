---
layout: parameter
name: OUT_BLH_MASK
display_name: BLHeli Output Mask
description: A bitmask of output channels configured for BLHeli pass-through and telemetry.
default_value: 0
range: 0 4294967295
units: 
group: OUT
visual_asset_id: dshot_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Output Mask (OUT_BLH_MASK)

## Description
`OUT_BLH_MASK` tells the autopilot which motors are "Smart ESCs" (BLHeli_S, BLHeli_32, or AM32).

Enabling these bits allows:
1.  **DShot Pass-through:** Change ESC settings using the BLHeliSuite configurator.
2.  **Telemetry:** Read RPM, Temperature, and Voltage from the ESCs.

*   **Bit 0 (1):** Servo 1
*   **Bit 1 (2):** Servo 2

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Set this bitmask to match your motor output channels (e.g., **15** for a standard Quad).
*   **Reboot Required:** Yes.