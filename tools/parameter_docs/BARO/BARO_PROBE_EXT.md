---
layout: parameter
name: BARO_PROBE_EXT
display_name: External Barometers to Probe
description: Bitmask of external I2C barometer types to search for during boot.
default_value: 0
range: 0 16383
units: 
group: BARO
visual_asset_id: i2c_bus_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp#L183
---

# External Barometers to Probe (BARO_PROBE_EXT)

## Description
`BARO_PROBE_EXT` tells ArduPilot which specific barometer hardware to look for on the external I2C bus. 

By default, the autopilot attempts to detect the most common sensors automatically. However, if you are using an unusual or newer sensor that isn't being found, you may need to enable its bit in this parameter.

*   **Bit 0:** BMP085
*   **Bit 1:** BMP280
*   **Bit 2:** MS5611
*   **Bit 3:** MS5607
*   **Bit 10:** BMP388
*   **Bit 11:** SPL06

## Tuning & Behavior
*   **Default:** 0 (Standard auto-detection).
*   **Usage:** Only modify this if your external barometer is not being detected (Instance 2 or 3 is missing in the GCS).
*   **Reboot Required:** Yes.