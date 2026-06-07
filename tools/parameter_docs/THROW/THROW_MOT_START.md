---
layout: parameter
name: THROW_MOT_START
display_name: Throw Mode Motor Start Behavior
description: Controls if the motors start spinning immediately upon arming or wait for the throw detection.
default_value: 0
range: 0 1
units: 
group: THROW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L693
---

# Throw Mode Motor Start Behavior (THROW_MOT_START)

## Description
`THROW_MOT_START` determines if the propellers are spinning while the drone is in your hand.

*   **0: Stopped.** The motors remain completely off after arming. They only start spinning once the autopilot detects that you have thrown the drone. This is the **Safest** for your hands.
*   **1: Spinning.** The motors start spinning at [MOT_SPIN_MIN](MOT_SPIN_MIN.html) as soon as you arm. This ensures the motors are "Ready" and synced, but increases the risk of finger injury during the toss.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Keep at **0** for safety. Only use **1** if your motors or ESCs have trouble starting reliably in free-fall.