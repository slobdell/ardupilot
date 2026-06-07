---
layout: parameter
name: RNGFND1_SNR_MIN
display_name: Rangefinder Minimum SNR (Sensor 1)
description: The minimum Signal-to-Noise Ratio (SNR) required to trust the rangefinder data.
default_value: 0
range: 0 255
units: 
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Backend_CAN.cpp#L37
---

# Rangefinder Minimum SNR (RNGFND1_SNR_MIN)

## Description
`RNGFND1_SNR_MIN` defines the "Quality Threshold" for your distance sensor. 

Digital rangefinders (like those using DroneCAN) often report the strength of the reflection (SNR). In environments with poor reflectivity (e.g. over tall grass or dark surfaces) or at the very edge of the sensor's range, the data can become noisy and unreliable. This parameter tells the autopilot to ignore any distance reading if its quality score falls below this limit.

## Tuning & Behavior
*   **Default:** 0 (Trust all data).
*   **Recommendation:** If you see your altitude "flickering" or jumping when the drone is high up or over difficult terrain, increase this value to **10** or **20**. 
*   **Note:** Setting this too high will cause the rangefinder to "drop out" (status 0) even when it might still be reporting valid data.
*   **Context:** This is primarily used by DroneCAN/UAVCAN rangefinders.