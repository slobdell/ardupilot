---
layout: parameter
name: EK3_WIND_PSCALE
display_name: EKF3 Wind Process Noise Scale
description: A scaling factor applied to the wind process noise when the vehicle is maneuvering.
default_value: 0.5
range: 0.0 1.0
units: 
group: EK3
visual_asset_id: ekf_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Wind Process Noise Scale (EK3_WIND_PSCALE)

## Description
`EK3_WIND_PSCALE` determines how much the EKF allows the wind estimate to change *while the drone is turning*.

When the drone maneuvers aggressively, it is harder to separate inertial forces from wind forces. This parameter tells the EKF to increase the uncertainty (noise) of the wind state during these times, allowing the estimate to shift faster to match reality.

*   **High Value (1.0):** Wind estimate adapts rapidly during turns.
*   **Low Value (0.0):** Wind estimate is "frozen" during turns.

## The Engineer's View
This parameter scales the `_windProcessNoise` dynamically based on the maneuver status.
$$ Q_{wind} = Q_{base} \times (1.0 + \text{Maneuver} \times \text{EK3\_WIND\_PSCALE}) $$

## Tuning & Behavior
*   **Default Value:** 0.5.
*   **Gliders/Soaring:** Increase to **1.0**. You want the wind estimate to update instantly as you circle in a thermal.
*   **Mapping Plane:** Decrease to **0.1**. You want a stable, averaged wind estimate for uniform track spacing.
