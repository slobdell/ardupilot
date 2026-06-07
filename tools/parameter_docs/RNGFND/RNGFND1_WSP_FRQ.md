---
layout: parameter
name: RNGFND1_WSP_FRQ
display_name: Wasp-LRF Measurement Frequency
description: Sets the update rate (in Hz) for the Wasp-LRF laser rangefinder.
default_value: 20
range: 20 10000
units: Hz
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Wasp.cpp#L45
---

# Wasp-LRF Measurement Frequency (RNGFND1_WSP_FRQ)

## Description
`RNGFND1_WSP_FRQ` controls how many times per second the Wasp-LRF laser rangefinder takes a distance measurement.

This is a hardware-specific parameter for the WASP-LRF sensor. A higher frequency provides more data for the autopilot to filter, which is useful for high-speed terrain following.

## Tuning & Behavior
*   **Default:** 20 Hz.
*   **Maximum:** Up to 10,000 Hz (if supported by the sensor and communication baud rate).
*   **Dependency:** Only active if [RNGFND1_TYPE](RNGFND1_TYPE.html) is set to 18 (WASP-LRF).