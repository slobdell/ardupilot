---
layout: parameter
name: PLND_TYPE
display_name: Precision Landing Type
description: Selects the hardware interface/sensor type used for precision landing.
default_value: 0
range: 0 4
units: 
group: PLND
visual_asset_id: precland_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L46
---

# Precision Landing Type (PLND_TYPE)

## Description
`PLND_TYPE` tells the autopilot what kind of eye it's using to find the landing target.

*   **0: None.**
*   **1: MAVLink.** The drone receives target coordinates from an external computer or camera (e.g. OpenMV) via a telemetry port.
*   **2: IRLock.** Specifically for the MarkOne IRLock sensor (IR Beacon).
*   **4: SITL.** Simulation mode for testing.

## Tuning & Behavior
*   **Reboot Required:** Yes.
