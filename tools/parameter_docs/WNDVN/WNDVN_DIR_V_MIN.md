---
layout: parameter
name: WNDVN_DIR_V_MIN
display_name: Wind Vane Min Voltage
description: The minimum analog voltage reported by the wind vane at its 0-degree limit.
default_value: 0
range: 0 5.0
units: V
group: WNDVN
visual_asset_id: windvane_pin_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L64
---

# Wind Vane Min Voltage (WNDVN_DIR_V_MIN)

## Description
`WNDVN_DIR_V_MIN` calibrates the "Start" of the rotation for an **Analog** wind vane.

Most analog wind vanes use a potentiometer that maps 0-360 degrees of rotation to a voltage range (e.g. 0.0V to 3.3V). This parameter defines the voltage that the autopilot should interpret as the very beginning of that rotation.

## Tuning & Behavior
*   **Default:** 0V.
*   **Calibration:** Rotate the wind vane manually to its mechanical start point (often marked on the sensor) and observe the voltage in your GCS. Enter that value here.
*   **Constraint:** On most modern flight controllers, the maximum readable voltage is 3.3V.