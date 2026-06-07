---
layout: parameter
name: TEMP1_A1
display_name: Temperature Polynomial Coefficient A1 (Sensor 1)
description: The 1st order coefficient (linear scale) for the analog temperature conversion formula.
default_value: 0
range: 
units: 
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Analog.cpp#L42
---

# Temperature Polynomial Coefficient A1 (TEMP1_A1)

## Description
`TEMP1_A1` is the linear part of the 5th-order polynomial used to calculate temperature from analog voltage.

*   **Linear Scale:** It defines how many degrees the temperature changes for every 1 volt increase.
*   **Formula:** $T = A_0 + (A_1 \cdot V) + (A_2 \cdot V^2) + \dots$

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Consult your sensor's datasheet for the "Slope" or "Scale" value.
*   **Note:** Only used if [TEMP1_TYPE](TEMP1_TYPE.html) is set to **5 (Analog)**.