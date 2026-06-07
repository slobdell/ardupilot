---
layout: parameter
name: SERVO_BLH_TEST
display_name: BLHeli Motor Test
description: Triggers a motor test sequence for BLHeli ESCs.
default_value: 0
range: 0 1
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Motor Test (SERVO_BLH_TEST)

## Description
`SERVO_BLH_TEST` runs the DShot beacon.

Setting this to **1** sends a command to all ESCs to beep. This confirms that the DShot communication link is working, even if the motors aren't spinning.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Test (Beep).