---
layout: parameter
name: TUNE_CHAN_MIN
display_name: Tuning Channel Minimum PWM
description: The minimum PWM value received from the transmitter for the tuning channel.
default_value: 1000
range: 900 2100
units: PWM
group: TUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Tuning/AP_Tuning.cpp#L27
---

# Tuning Channel Minimum PWM (TUNE_CHAN_MIN)

## Description
`TUNE_CHAN_MIN` defines the "Zero Position" for the RC channel used for in-flight tuning. 

When your transmitter knob or slider is at its lowest position and sends this PWM value, the autopilot will set the parameter being tuned to [TUNE_MIN](TUNE_MIN.html).

## Tuning & Behavior
*   **Default:** 1000.
*   **Calibration:** Ensure this matches the minimum PWM reported during your radio calibration for the channel assigned to tuning.