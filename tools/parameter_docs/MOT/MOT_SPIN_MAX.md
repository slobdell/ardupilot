---
layout: parameter
name: MOT_SPIN_MAX
display_name: Motor Spin maximum
description: The maximum throttle output to the motors during flight.
default_value: 0.95
range: 0.9 1.0
units: 
group: MOT
visual_asset_id: mot_spin_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L116
---

# Motor Spin maximum (MOT_SPIN_MAX)

## Description
`MOT_SPIN_MAX` sets the upper limit for the throttle sent to the ESCs.

ArduPilot reserves the top few percent of the throttle range for the attitude controller. Even at full stick deflection, the average motor output is clamped to `MOT_SPIN_MAX` to ensure there is always "headroom" for the stabilization loop to increase the speed of one motor (to roll or pitch) without hitting the 100% saturation limit instantly.

## The Mathematics
$$ \text{Max Output} = \text{MOT\_SPIN\_MAX} $$

If `MOT_SPIN_MAX` is 0.95, the motors will never be commanded above 95% throttle for lift generation, leaving 5% headroom for yaw/roll/pitch authority at full throttle.

## The Engineer's View
Used in `AP_MotorsMulticopter::output_to_motors()`.
Ideally, this matches the point where the thrust curve flattens out (diminishing returns).

## Tuning & Behavior
*   **Default Value:** 0.95 (95%)
*   **Range:** 0.9 - 1.0
*   **Recommendation:** Leave at **0.95**.
    *   **0.90:** Safer for stability at full throttle, but slight loss of top speed.
    *   **1.00:** Disables headroom. Not recommended, as the drone may lose yaw/roll authority during a full-throttle punch-out (unless `MOT_YAW_HEADROOM` saves it).