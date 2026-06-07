---
layout: parameter
name: TUNE_CHAN_MAX
display_name: Tuning Channel Maximum PWM
description: The maximum PWM value received from the transmitter for the tuning channel.
default_value: 2000
range: 900 2100
units: PWM
group: TUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Tuning/AP_Tuning.cpp#L34
---

# Tuning Channel Maximum PWM (TUNE_CHAN_MAX)

## Description
`TUNE_CHAN_MAX` defines the "Full Scale" position for the tuning channel.

When your transmitter knob is at its highest position and sends this PWM value, the autopilot sets the parameter being tuned to [TUNE_MAX](TUNE_MAX.html).