---
layout: parameter
name: ATC_SPEED_P
display_name: Speed Control P Gain
description: The proportional gain for the rover speed controller. Converts speed error into throttle output.
default_value: 0.2
range: 0.01 2.0
units: 
group: ATC
visual_asset_id: atc_speed_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L125
---

# Speed Control P Gain (ATC_SPEED_P)

## Description
`ATC_SPEED_P` is the main "Throttle" knob.

If the rover is driving 1 m/s slower than it should be, this parameter determines how much extra throttle to apply.

*   **Low Value:** Sluggish acceleration. The rover struggles to reach top speed uphill.
*   **High Value:** Aggressive acceleration. May oscillate (surge) speed.

## The Mathematics
$$ \text{Throttle} = k_P \cdot (\text{Speed}_{target} - \text{Speed}_{actual}) $$

## Tuning & Behavior
*   **Default Value:** 0.20.
*   **Tuning:** Increase P until the rover surges/pulses speed, then back off by 20%.
