---
layout: parameter
name: RNGFND1_PWRRNG
display_name: Rangefinder Power Save Range (Sensor 1)
description: The altitude above which the rangefinder is put into sleep mode to save power.
default_value: 0
range: 0 32767
units: m
group: RNGFND
visual_asset_id: rngfnd_range_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L90
---

# Rangefinder Power Save Range (RNGFND1_PWRRNG)

## Description
`RNGFND1_PWRRNG` allows the autopilot to turn off the distance sensor when the drone is flying high.

Some Lidar sensors consume significant power. If you are flying a long-range mapping mission at 100m altitude, but your Lidar only works up to 20m, keeping it active is wasteful. This parameter puts the sensor into a low-power "Sleep" state when the estimated terrain clearance exceeds this value.

*   **0:** Disabled (Sensor is always ON).
*   **Value (m):** Altitude above terrain at which the sensor sleeps.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Set to slightly less than your sensor's maximum effective range.
*   **Note:** This requires the sensor driver to support a low-power mode (e.g. Lightware).