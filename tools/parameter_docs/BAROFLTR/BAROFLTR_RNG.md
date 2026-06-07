---
layout: parameter
name: BAROFLTR_RNG
display_name: Range in which sample is accepted
description: This sets the range around the average value that new samples must be within to be accepted. This can help reduce the impact of noise on sensors that are on long I2C cables.
default_value: 0
range: 0 100
units: %
group: BAROFLTR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# Range in which sample is accepted (BAROFLTR_RNG)

## Description
A noise filter that rejects barometer samples that deviate too far from the rolling average.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 0 to 100 %
*   **Useful for mitigating spikes in altitude data caused by electrical interference or long cable runs.**