---
layout: parameter
name: TEMP1_A0
display_name: Temperature Polynomial Coefficient A0 (Sensor 1)
description: The 0th order coefficient (offset) for the analog temperature conversion formula.
default_value: 0
range: 
units: 
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Analog.cpp#L37
---

# Temperature Polynomial Coefficient A0 (TEMP1_A0)

## Description
`TEMP1_A0` is the first part of a 5th-order polynomial used to translate raw analog voltage from a thermistor or probe into a human-readable temperature in degrees Celsius.

In its simplest form (linear), `A0` acts as the offset. In a complex curve, it works with `A1` through `A5` to fit the specific response curve of your sensor.

## The Mathematics
The autopilot calculates the temperature ($T$) from the measured voltage ($V$) using this formula:

$$ T = A_0 + (A_1 \cdot V) + (A_2 \cdot V^2) + (A_3 \cdot V^3) + (A_4 \cdot V^4) + (A_5 \cdot V^5) $$

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** For most standard analog sensors, you will find these coefficients in the manufacturer's data sheet or by performing a curve-fitting calibration in a spreadsheet.
*   **Note:** This only applies if `TEMP1_TYPE` is set to **5 (Analog)**.