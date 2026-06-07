---
layout: parameter
name: RNGFND1_STOP_PIN
display_name: Rangefinder Stop Pin
description: Digital pin used to enable or disable the rangefinder to save power.
default_value: -1
range: -1 103
units: 
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L73
---

# Rangefinder Stop Pin (RNGFND1_STOP_PIN)

## Description
`RNGFND1_STOP_PIN` allows ArduPilot to turn the rangefinder sensor ON and OFF dynamically. 

This is primarily used to save battery power or to prevent the sensor from producing noisy signals when the vehicle is flying too high for the sensor to work (Out of Range). 

*   **-1:** Disabled (Sensor is always ON).
*   **0-103:** Physical GPIO pin number used to control the sensor's enable/stop line.

## Tuning & Behavior
*   **Default:** -1.
*   **Usage:** If a pin is configured, the autopilot will set the pin HIGH to enable the sensor and LOW to disable it when the estimated altitude is well beyond the sensor's maximum range.