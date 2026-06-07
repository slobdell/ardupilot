---
layout: parameter
name: BRD_RADIO_ABTIME
display_name: Internal Radio Auto-Bind Timeout
description: Timeout (in seconds) before the radio enters auto-bind mode when no signal is detected.
default_value: 0
range: 0 120
units: s
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L129
---

# Internal Radio Auto-Bind Timeout (BRD_RADIO_ABTIME)

## Description
`BRD_RADIO_ABTIME` determines how long the integrated receiver waits for its "known" transmitter before it gives up and enters **Auto-Bind** mode.

This is a convenience feature for consumer drones. If you lose or replace your transmitter, you can power on the drone and wait for this timeout to expire. The drone will then start looking for a new transmitter to bind with.

*   **0 (Default):** Auto-bind is disabled. You must trigger binding manually (usually via a button or MAVLink command).
*   **1-120:** Wait time in seconds.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Set to **10** or **20** if you want the drone to automatically enter bind mode if you power it on before your transmitter.