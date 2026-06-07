---
layout: parameter
name: FLTR_RNG
display_name: Range in which sample is accepted
description: This sets the range around the average value that new samples must be within to be accepted.
default_value: 0
range: 0 100
units: %
group: FLTR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# Range in which sample is accepted (FLTR_RNG)

## Description
A noise filter that rejects barometer samples that deviate too far from the rolling average.