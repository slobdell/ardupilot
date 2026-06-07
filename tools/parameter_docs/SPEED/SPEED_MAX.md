---
layout: parameter
name: SPEED_MAX
display_name: "Speed maximum"
description: "Maximum speed vehicle can obtain at full throttle"
default_value: 0.0f
range: 0 30
units: "m/s"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L629
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.h#L410
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Speed maximum (SPEED_MAX)

## Description
This parameter defines the **Physical Maximum Speed** of the Rover at 100% throttle. The navigation controller uses this value to scale its throttle output. If set to 0, the autopilot will attempt to estimate it based on `CRUISE_SPEED` and `CRUISE_THROTTLE`, but setting it explicitly provides better performance.

## The Mathematics
$$ \text{Throttle}_{demand} \approx \frac{\text{Target Speed}}{\text{SPEED_MAX}} $$

## The Engineer's View
Defined in `Rover/Parameters.cpp`. Used in `AR_AttitudeControl` (the Ackermann/Skid steering controller) to normalize speed demands to throttle percentages.
*   **If 0:** `SPEED_MAX` is derived: $\text{SPEED_MAX} = \text{CRUISE_SPEED} / (\text{CRUISE_THROTTLE} / 100) $.

## Tuning & Behavior
*   **Default Value:** 0 (Auto-calculate)
*   **Set to:** The actual top speed of the rover in meters/second.
*   **Effect:** Improving this value helps the speed controller achieve target speeds more accurately without overshooting (if too low) or undershooting (if too high).
