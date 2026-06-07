---
layout: parameter
name: EK2_IMU_MASK
display_name: Bitmask of active IMUs
description: Bitmap of IMUs to use in EKF2. A separate instance of EKF2 will be started for each IMU selected.
default_value: 3
range: 
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Bitmask of active IMUs (EK2_IMU_MASK)

## Description
Defines which physical IMUs (Accelerometers/Gyros) will have an associated EKF2 core instance.