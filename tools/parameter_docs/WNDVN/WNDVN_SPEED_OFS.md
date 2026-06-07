---
layout: parameter
name: WNDVN_SPEED_OFS
display_name: Wind Speed Voltage Offset
description: The analog voltage reported by the sensor when the wind speed is zero.
default_value: 0
range: 0 3.3
units: V
group: WNDVN
visual_asset_id: windvane_pin_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L145
---

# Wind Speed Voltage Offset (WNDVN_SPEED_OFS)

## Description
`WNDVN_SPEED_OFS` calibrates the "Zero Point" for **Analog** wind speed sensors. 

Many analog anemometers (like the Modern Devices sensor) output a small baseline voltage even when there is no wind. This parameter tells the autopilot to treat that specific voltage as "0.0 m/s," ensuring that subsequent speed readings are accurate.

## Tuning & Behavior
*   **Default:** 0.
*   **Calibration:** Power on the vehicle in a room with perfectly still air. Observe the raw voltage from the sensor in the GCS status tab (or via logs) and enter that value here.
*   **Effect:** If this value is too high, the drone will under-report wind speed. If too low, it will report a phantom wind even when stationary.