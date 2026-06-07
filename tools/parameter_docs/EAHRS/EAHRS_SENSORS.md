---
layout: parameter
name: EAHRS_SENSORS
display_name: "External AHRS sensors"
description: "Bitmask of sensors to use from the External AHRS"
default_value: 15
range: 0 15
units: "Bitmask"
group: EAHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ExternalAHRS/AP_ExternalAHRS.cpp#L84
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ExternalAHRS/AP_ExternalAHRS.h#L189
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# External AHRS sensors (EAHRS_SENSORS)

## Description
This parameter determines which sensor data streams from the connected External AHRS (e.g., VectorNav, MicroStrain) should be consumed by the autopilot. This allows for a hybrid setup where, for example, the external GPS and IMU are used, but the internal barometer is preferred.

## The Mathematics
Bitmask logic:
*   **Bit 0:** Use GPS data.
*   **Bit 1:** Use IMU data (Accel/Gyro).
*   **Bit 2:** Use Barometer data.
*   **Bit 3:** Use Compass/Magnetometer data.

## The Engineer's View
Defined in `libraries/AP_ExternalAHRS/AP_ExternalAHRS.cpp`.
*   **Default (15 / 0xF):** Use all available sensors from the external unit.
*   **Usage:** If the external unit has a poor quality barometer or is mounted in a pressurized box, you might disable Bit 2.

## Tuning & Behavior
*   **Default Value:** 15 (All)
*   **Set to:** The sum of the bits for the desired sensors.