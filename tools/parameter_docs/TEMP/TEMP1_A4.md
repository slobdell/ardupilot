---
layout: parameter
name: TEMP1_A4
display_name: Temperature Polynomial Coefficient A4 (Sensor 1)
description: The 4th order coefficient for the analog temperature conversion formula.
default_value: 0
range: 
units: 
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Analog.cpp#L57
---

# Temperature Polynomial Coefficient A4 (TEMP1_A4)

## Description
`TEMP1_A4` is the fourth-order part of the 5th-order polynomial used to calculate temperature from analog voltage.

*   **Role:** Used for extremely precise curve fitting on high-end specialized analog probes.
*   **Formula:** $T = A_0 + (A_1 \cdot V) + (A_ linear \cdot V^2) + (A_3 \cdot V^3) + (A_4 \cdot V^4) + \dots$