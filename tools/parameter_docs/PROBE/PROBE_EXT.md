---
layout: parameter
title: PROBE_EXT
name: External barometers to probe
group: PROBE
---

# PROBE_EXT: External barometers to probe

## Description
This sets which types of external i2c barometer to look for. It is a bitmask of barometer types.

## Values
- **Bitmask:**
  - **Bit 0:** BMP085
  - **Bit 1:** BMP280
  - **Bit 2:** MS5611
  - **Bit 3:** MS5607
  - **Bit 4:** MS5637
  - **Bit 5:** FBM320
  - **Bit 6:** DPS280
  - **Bit 7:** LPS25H
  - **Bit 8:** KELLER
  - **Bit 9:** MS5837
  - **Bit 10:** BMP388
  - **Bit 11:** ICP10100
  - **Bit 12:** ICP20100
  - **Bit 13:** SPL06

- **Default:** Varies by board (HAL_BARO_PROBE_EXT_DEFAULT)

## Description
This parameter controls which barometer drivers are loaded when searching the external I2C bus.

- **Usage:** If you connect an external I2C barometer (e.g., on a GPS module), this parameter determines which chips the autopilot will try to find.
- **Optimization:** You can disable unused bits to speed up the boot process and prevent false detection of other I2C devices.

## Source Code
[ardupilot/libraries/AP_Baro/AP_Baro.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.cpp#L183)

