---
layout: parameter
name: RNGFND1_OFFSET
display_name: Rangefinder Offset (Sensor 1)
description: Calibrates the zero-distance reference or adds a linear offset to the reading.
default_value: 0
range: -1.0 1.0
units: V
group: RNGFND
visual_asset_id: rngfnd_scaling_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L43
---

# Rangefinder Offset (RNGFND1_OFFSET)

## Description
`RNGFND1_OFFSET` provides a linear correction to the distance measurement. 

For **Analog** sensors, this is an electrical offset in Volts (e.g. the sensor outputs 0.2V even at 0cm). For **PWM** sensors, this is an additive offset in centimeters (e.g. to account for the sensor being mounted 10cm inside the fuselage).

$$ \text{Distance} = (\text{Voltage} \times \text{Scaling}) + \text{Offset} $$

## Tuning & Behavior
*   **Default:** 0.
*   **Calibration:** Place the vehicle at a known distance from a wall. If the reported distance is consistently too short, increase the offset.