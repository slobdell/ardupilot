---
layout: parameter
name: TEMP1_A2
display_name: Temperature Polynomial Coefficient A2 (Sensor 1)
description: The 2nd order coefficient (curviness) for the analog temperature conversion formula.
default_value: 0
range: 
units: 
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Analog.cpp#L47
---

# Temperature Polynomial Coefficient A2 (TEMP1_A2)

## Description
`TEMP1_A2` is the second-order (square) part of the 5th-order polynomial used to calculate temperature from analog voltage.

*   **Role:** Defines the curvature of the sensor's response. Most low-cost thermistors are non-linear and require this coefficient to provide accurate readings across a wide temperature range.
*   **Formula:** $T = A_0 + (A_1 \cdot V) + (A_2 \cdot V^2) + \dots$

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Consult your sensor's datasheet or a calibration table. 
*   **Note:** Only used if [TEMP1_TYPE](TEMP1_TYPE.html) is set to **5 (Analog)**.