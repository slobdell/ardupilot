---
layout: parameter
name: RPM1_SCALING
display_name: RPM Scaling (Sensor 1)
description: Calibrates the relationship between sensor pulses and actual revolutions.
default_value: 1.0
range: 0 100
units: 
group: RPM
visual_asset_id: rpm_scaling_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RPM/AP_RPM_Params.cpp#L34
---

# RPM Scaling (RPM1_SCALING)

## Description
`RPM1_SCALING` is the "Gear Ratio" or "Pole Count" setting for your RPM sensor. It tells the autopilot how many pulses from the sensor equal one full revolution of the motor or shaft.

$$ \text{RPM} = \text{Sensor Rate} \times \text{RPM1_SCALING} $$

*   **Example (Hall Effect):** If you have 1 magnet on the shaft, set Scaling to **1.0**.
*   **Example (Pole Count):** If using an ESC sensor on a 14-pole motor, the sensor sends 7 pulses per rev. Set Scaling to $1/7 
approx$ **0.142**.

## Tuning & Behavior
*   **Default:** 1.0.
*   **Accuracy:** Verify the reported RPM against a handheld tachometer. If the reported RPM is exactly double the actual RPM, divide your Scaling value by 2.