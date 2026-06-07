---
layout: parameter
name: MOT_BAT_CURR_TC
display_name: Battery Current Time Constant
description: The time constant for the low-pass filter used in battery current limiting.
default_value: 5.0
range: 0 10.0
units: s
group: MOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L131
---

# Battery Current Time Constant (MOT_BAT_CURR_TC)

## Description
`MOT_BAT_CURR_TC` determines how quickly the autopilot reacts to an over-current situation. 

ArduPilot has a "Current Limiter" that reduces throttle if the drone pulls more Amps than your battery or ESCs can handle. This parameter acts as a "Buffer" – a higher value allows brief current spikes (like a fast punch-out) without cutting power, while still protecting against sustained high current that could melt wires or blow a fuse.

## Tuning & Behavior
*   **Default:** 5.0 seconds.
*   **High Value (e.g. 10.0):** Very slow reaction. Good for high-performance drones that need occasional bursts of power.
*   **Low Value (e.g. 1.0):** Fast reaction. Best for protecting fragile batteries or electronics from any significant current surge.
*   **Dependencies:** Only active if `MOT_BAT_CURR_MAX` is configured.