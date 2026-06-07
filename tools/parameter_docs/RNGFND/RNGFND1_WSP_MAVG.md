---
layout: parameter
name: RNGFND1_WSP_MAVG
display_name: Wasp-LRF Moving Average
description: The number of previous samples to include in the moving average filter.
default_value: 4
range: 0 255
units: Samples
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Wasp.cpp#L32
---

# Wasp-LRF Moving Average (RNGFND1_WSP_MAVG)

## Description
`RNGFND1_WSP_MAVG` defines the window size for a smoothing filter inside the **Wasp-LRF** sensor driver. 

A higher number of samples in the average leads to more stable altitude readings but introduces a small amount of latency (lag) as the drone moves vertically.