---
layout: parameter
name: BATT_BAL_RATE
display_name: Battery Balancer Update Rate
description: The frequency (in Hz) for updating and reporting individual cell balance data.
default_value: 10
range: 1 50
units: Hz
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattBalance.cpp
---

# Battery Balancer Update Rate (BATT_BAL_RATE)

## Description
`BATT_BAL_RATE` defines how often individual cell voltages are sampled and reported over the communication bus.

A higher rate provides more immediate detection of an individual cell failing or sagging under load, which is critical for high-performance lithium battery management.