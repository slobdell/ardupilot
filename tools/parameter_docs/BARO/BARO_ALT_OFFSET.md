---
layout: parameter
name: BARO_ALT_OFFSET
display_name: "Altitude offset"
description: "Altitude offset in meters added to barometric altitude."
default_value: 0
range: null
units: "m"
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.cpp#L118
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Altitude offset (BARO_ALT_OFFSET)

## Description
This parameter allows for a manual bias (offset) to be added to the calculated barometric altitude. It is primarily used by Ground Control Stations (GCS) to synchronize the aircraft's altitude with a known ground reference point or a GCS-integrated barometer.

It essentially "shifts" the entire altitude profile up or down by the specified number of meters.

## The Mathematics
The offset is added directly to the final altitude calculation for every sensor instance.

$$ Alt_{reported} = Alt_{raw} + BARO\_ALT\_OFFSET $$

To prevent "jerking" the flight controllers (which could upset the EKF), ArduPilot slews this value slowly over time rather than applying it as a step function.

## The Engineer's View
In `AP_Baro::update()`, the code checks if `_alt_offset` has changed:
`_alt_offset_active = (0.98f*_alt_offset_active) + (0.02f*_alt_offset);`
This implementation acts as a low-pass filter (98% old, 2% new) to smoothly transition to a new offset.
The value is reset to **0** every time a full barometer calibration is performed (e.g., on reboot).

## Tuning & Behavior
*   **Default Value:** 0 meters.
*   **Usage:** Typically modified via MAVLink by a GCS rather than tuned manually by a user. 
*   **Persistence:** This value is saved to EEPROM but is automatically reset to 0 during the `AP_Baro::calibrate()` call on boot.

