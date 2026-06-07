---
layout: parameter
name: SERVO_BLH_TMOUT
display_name: BLHeli Passthrough Timeout
description: The time (in seconds) after which BLHeli passthrough mode is automatically disabled if no activity is detected.
default_value: 0
range: 0 600
units: s
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Passthrough Timeout (SERVO_BLH_TMOUT)

## Description
`SERVO_BLH_TMOUT` is a safety feature for the BLHeliSuite bridge.

When you connect to BLHeliSuite, the autopilot enters a special "Passthrough" mode where it stops sending motor commands and lets the PC talk to the ESCs. This parameter ensures the autopilot exits this mode automatically if you disconnect or crash the PC app, preventing a locked-up flight controller.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled/No timeout).