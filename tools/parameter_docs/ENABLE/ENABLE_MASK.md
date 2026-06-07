---
layout: parameter
name: ENABLE_MASK
display_name: IMU Enable Mask
description: Bitmask of IMUs to enable.
default_value: 127
range: 
units: 
group: ENABLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_InertialSensor/AP_InertialSensor.cpp
---

# IMU Enable Mask (ENABLE_MASK)

## Description
Defines which physical IMUs (Inertial Measurement Units) the flight controller should attempt to initialize and use.
*   **Default Value:** 127 (Enable all detected IMUs)
*   **Bitmask corresponds to IMU indices 1 through 7.**