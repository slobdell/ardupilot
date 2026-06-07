---
layout: parameter
name: RNGFND1_FUNCTION
display_name: Rangefinder Voltage Function
description: Selects the mathematical formula used to convert voltage to distance.
default_value: 0
range: 0 2
units: 
group: RNGFND
visual_asset_id: rngfnd_scaling_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L50
---

# Rangefinder Voltage Function (RNGFND1_FUNCTION)

## Description
`RNGFND1_FUNCTION` defines the relationship between the sensor's output voltage and the actual physical distance. This is only used for **Analog** sensors.

*   **0: Linear (Standard).** $\text{Dist} = (\text{Volt} - \text{Offset}) \times \text{Scaling}$. Used for most ultrasonic and infrared sensors.
*   **1: Inverted.** $\text{Dist} = (\text{Offset} - \text{Volt}) \times \text{Scaling}$. Used for sensors where voltage decreases as distance increases.
*   **2: Hyperbolic.** $\text{Dist} = \frac{\text{Scaling}}{\text{Volt} - \text{Offset}}$. 

## Tuning & Behavior
*   **Default:** 0 (Linear).
*   **Recommendation:** Check your sensor's data sheet. If the graph of "Distance vs Voltage" is a straight line, use **Linear**. If it's a curve, you may need **Hyperbolic**.