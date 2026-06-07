---
layout: parameter
name: BAROPROBE_EXT
display_name: External barometers to probe
description: This sets which types of external i2c barometer to look for. It is a bitmask of barometer types.
default_value: 0
range: 
units: 
group: BAROPROBE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp
---

# External barometers to probe (BAROPROBE_EXT)

## Description
Bitmask selecting which specific barometer hardware types ArduPilot should search for on the I2C bus.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask Examples:**
    *   Bit 0: BMP085
    *   Bit 1: BMP280
    *   Bit 2: MS5611
    *   Bit 10: BMP388
    *   Bit 11: SPL06