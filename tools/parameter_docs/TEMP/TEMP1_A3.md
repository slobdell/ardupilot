---
layout: parameter
name: TEMP1_A3
display_name: Temperature Polynomial Coefficient A3 (Sensor 1)
description: The 3rd order coefficient for the analog temperature conversion formula.
default_value: 0
range: 
units: 
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Analog.cpp#L52
---

# Temperature Polynomial Coefficient A3 (TEMP1_A3)

## Description
`TEMP1_A3` is the third-order (cubic) part of the 5th-order polynomial used to calculate temperature from analog voltage.

*   **Role:** Refines the accuracy of non-linear sensors. 
*   **Formula:** $T = A_0 + (A_1 \cdot V) + (A_2 \cdot V^2) + (A_3 \cdot V^3) + \dots$