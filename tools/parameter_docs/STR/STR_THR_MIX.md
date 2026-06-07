---
default_value: 0.5
description: Steering vs Throttle priorisation.  Higher numbers prioritise steering,
  lower numbers prioritise throttle.  Only valid for Skid Steering vehicles
display_name: Motor steering vs throttle prioritisation
group: STR
investigation_status: complete
layout: parameter
name: STR_THR_MIX
range: 0.2 1.0
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AR_Motors/AP_MotorsUGV.cpp#L104
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AR_Motors/AP_MotorsUGV.h#L211
units: null
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Motor steering vs throttle prioritisation (STR_THR_MIX)

## Description
This parameter manages the "Saturation Mixer" logic for skid-steer Rovers. 
In a skid-steer vehicle (like a tank), turning is achieved by speeding up one side and slowing down the other. If you are already at 100% Throttle, you cannot speed up one side further to turn.

`STR_THR_MIX` decides what to sacrifice when the driver requests both full speed and a turn:
*   **High Value (> 0.5):** Sacrifice Speed to ensure Turning (Slows down to turn).
*   **Low Value (< 0.5):** Sacrifice Turning to maintain Speed (Turns less sharp to keep moving fast).

## The Mathematics
The mixer checks if `Throttle + |Steering| > 1.0` (Saturation).
If saturated, it calculates a scaling factor based on `STR_THR_MIX` ($\alpha$).

**If $\alpha \ge 0.5$ (Prioritize Steering):**
$$ \text{Steering} = \text{Steering}_{cmd} \times \text{FairScaler} $$
$$ \text{Throttle} = \text{Throttle}_{cmd} \times \text{interpolate}(\text{FairScaler}, 1.0, 0.5 - \alpha) $$
*(Effectively reduces throttle to make "headroom" for the steering command)*

**If $\alpha < 0.5$ (Prioritize Throttle):**
$$ \text{Throttle} = \text{Throttle}_{cmd} \times \text{FairScaler} $$
$$ \text{Steering} = \text{Steering}_{cmd} \times \text{interpolate}(\text{FairScaler}, 1.0, \alpha) $$
*(Effectively reduces steering command)*

## The Engineer's View
In `AP_MotorsUGV::output_skid_steering`:
The code calculates `max_output = throttle + |steering|`.
If `max_output > 1.0`, it enters the saturation handling logic described above.
This ensures that the output to the motors never exceeds the physical limits while attempting to respect the user's priority preference.

## Tuning & Behavior
*   **Default Value:** 0.5 (Balanced)
*   **Range:** 0.2 to 1.0
*   **1.0 (Steering Priority):** The vehicle will slow down significantly to ensure it hits the requested turn rate. Recommended for autonomous missions where path tracking is critical.
*   **0.2 (Throttle Priority):** The vehicle will prioritize speed, potentially missing a turn radius if moving fast. Useful for racing or manual FPV driving where flow is more important than precision.
