---
layout: parameter
name: SERVO_BLH_DEBUG
display_name: BLHeli Debug Enable
description: Enables debugging messages for BLHeli ESC communication.
default_value: 0
range: 0 1
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Debug Enable (SERVO_BLH_DEBUG)

## Description
`SERVO_BLH_DEBUG` floods the log with ESC traffic.

Use this only if your ESCs are not connecting or telemetry is failing. It records the raw DShot or serial bytes exchanged between the flight controller and the ESCs.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.
*   **Warning:** Can consume significant CPU and SD card bandwidth. Disable after troubleshooting.