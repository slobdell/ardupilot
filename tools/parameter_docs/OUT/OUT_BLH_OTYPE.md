---
layout: parameter
name: OUT_BLH_OTYPE
display_name: BLHeli Output Type
description: Selects the protocol type for BLHeli pass-through and telemetry.
default_value: 0
range: 0 4
units: 
group: OUT
visual_asset_id: dshot_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Output Type (OUT_BLH_OTYPE)

## Description
`OUT_BLH_OTYPE` selects the "Language" the autopilot uses to talk to your ESCs for telemetry.

*   **0: None.** No telemetry.
*   **1: BLHeli_S / BLHeli_32.** Standard DShot telemetry.
*   **4: AM32.** For AM32 based ESCs.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Match your ESC hardware. Most modern ESCs use **1**.