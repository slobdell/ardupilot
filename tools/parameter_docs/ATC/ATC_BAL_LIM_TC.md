---
layout: parameter
name: ATC_BAL_LIM_TC
display_name: Pitch control limit time constant
description: The time constant (in seconds) used to limit the pitch angle of a self-balancing robot when it approaches a power limit.
default_value: 0.5
range: 0.0 5.0
units: s
group: ATC
visual_asset_id: atc_bal_lim_tc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L427
---

# Pitch control limit time constant (ATC_BAL_LIM_TC)

## Description
`ATC_BAL_LIM_TC` is a safety parameter for **Balance Bots** (Segway-style rovers).

A balancing robot stays upright by moving its wheels to stay under its center of mass. If the motors reach 100% power (saturation), the robot can no longer accelerate fast enough to catch itself if it tilts further. This parameter defines how quickly the autopilot should "pull back" the maximum allowed tilt angle when it detects that the motors are working too hard.

*   **Low Value (e.g. 0.1):** The drone aggressively limits its lean angle the moment it feels underpowered. High safety, but might feel "weak."
*   **High Value (e.g. 2.0):** The drone allows for longer "pushes" near the limit, relying on momentum.

## The Mathematics
The pitch limit ($\theta_{lim}$) is dynamically adjusted based on throttle output:

$$ \dot{\theta}_{lim} = \frac{1}{\text{ATC\_BAL\_LIM\_TC}} \cdot (\theta_{max} - \theta_{lim}) $$

When throttle exceeds `ATC_BAL_LIM_THR`, the limit is reduced. When throttle is low, the limit is "relaxed" back to its user-defined maximum.

## Tuning & Behavior
*   **Default Value:** 0.5 seconds.
*   **Recommendation:** If your balance bot frequently "falls over" forward during hard acceleration, decrease this value to **0.2** to force it to stay more upright.