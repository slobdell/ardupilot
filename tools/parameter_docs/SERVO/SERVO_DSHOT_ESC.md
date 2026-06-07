---
layout: parameter
name: SERVO_DSHOT_ESC
display_name: DShot ESC Type
description: Selects the specific DShot ESC protocol variant to enable extended telemetry features.
default_value: 0
range: 0 4
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_HAL/RCOutput.h#L248
---

# DShot ESC Type (SERVO_DSHOT_ESC)

## Description
`SERVO_DSHOT_ESC` tells the autopilot exactly what kind of DShot-capable ESCs you have connected.

While standard DShot works without this parameter, enabling the specific type allows for advanced features like **EDT (Extended DShot Telemetry)**, which sends temperature, voltage, and current data back to the flight controller over the single signal wire.

*   **0: None.** Standard DShot.
*   **1: BLHeli32 / AM32.** Supports standard telemetry commands.
*   **2: BLHeli_S.**
*   **3: BLHeli32 EDT.** Enables Extended DShot Telemetry (if supported by firmware).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **1** for most modern BLHeli_32/AM32 ESCs.
*   **Reboot Required:** Yes.
