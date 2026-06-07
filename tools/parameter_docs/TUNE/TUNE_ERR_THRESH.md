---
layout: parameter
name: TUNE_ERR_THRESH
display_name: Tuning Instability Threshold
description: The error threshold (RMS) above which the autopilot warns of instability during tuning.
default_value: 0.15
range: 0 1.0
units: 
group: TUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Tuning/AP_Tuning.cpp#L61
---

# Tuning Instability Threshold (TUNE_ERR_THRESH)

## Description
`TUNE_ERR_THRESH` is an "Over-Gain Alarm" for in-flight tuning.

As you increase PID gains using your transmitter knob, the drone's movements will become sharper. However, if the gains go too high, the drone will start to vibrate or oscillate (instability). This parameter monitors the root-mean-square (RMS) of the PID corrections. If the corrections become too large and fast (indicating oscillation), the autopilot will sound a buzzer alarm and send a "Controller Instability" message to your Ground Control Station.

## Tuning & Behavior
*   **Default:** 0.15.
*   **Recommendation:** Leave at **0.15**. If the alarm triggers, it means you have pushed your gains too far and should immediately lower the tuning knob.
*   **-1:** Disables the alarm.