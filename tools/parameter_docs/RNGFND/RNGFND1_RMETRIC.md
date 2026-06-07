---
layout: parameter
name: RNGFND1_RMETRIC
display_name: Rangefinder Ratiometric Enable
description: Defines if the analog rangefinder's output voltage scales with the supply voltage.
default_value: 1
range: 0 1
units: 
group: RNGFND
visual_asset_id: rngfnd_scaling_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L82
---

# Rangefinder Ratiometric Enable (RNGFND1_RMETRIC)

## Description
`RNGFND1_RMETRIC` calibrates the autopilot's ADC (Analog-to-Digital Converter) behavior for **Analog** distance sensors.

*   **1: Yes (Standard).** Most simple analog sensors change their output voltage relative to the 5V supply. If the 5V rail drops slightly, the sensor's output drops too. The autopilot compensates for this by comparing the sensor voltage to the rail voltage.
*   **0: No.** Use this if the sensor has its own internal voltage regulator and outputs a constant voltage regardless of the input power (e.g. some high-end Lightware sensors).

## Tuning & Behavior
*   **Default:** 1.
*   **Recommendation:** Leave at **1** unless your sensor's manual explicitly states it has an internal voltage regulator.