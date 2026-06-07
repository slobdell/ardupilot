---
layout: parameter
name: COMPASS_FLTR_RNG
display_name: Range in which sample is accepted
description: This sets the range around the average value that new samples must be within to be accepted.
default_value: 0
range: 0 100
units: %
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Range in which sample is accepted (COMPASS_FLTR_RNG)

## Description
A noise-rejection filter for magnetometer data. Rejects samples that differ significantly from the recent average.
*   **0 disables the filter.**
