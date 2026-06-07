---
layout: parameter
name: LOIT_TYPE
display_name: Loiter type
description: Configures the movement behavior when the Rover/Boat is repositioning to stay within the Loiter circle.
default_value: 0
range: 0 2
units: 
group: LOIT
visual_asset_id: loiter_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L324
---

# Loiter type (LOIT_TYPE)

## Description
`LOIT_TYPE` is a **Rover-specific** parameter that tells the vehicle how to move when it drifts outside its loiter circle.

*   **0: Forward or Reverse.** The rover will take the shortest path back to the center, even if it means driving backward. (Recommended for standard rovers).
*   **1: Always Face Forward.** The vehicle will only drive forward to return to the point. It will perform a U-turn if necessary. (Recommended for boats without a reverse gear or large scale rovers).
*   **2: Always Face Stern.** The vehicle will only move backward to return. (Rarely used).

## The Mathematics
This parameter toggles the logic branch in the steering/throttle controller:
$$ \text{TargetHeading} = \begin{cases} \theta_{direct} & \text{if Type 1} \\ \theta_{direct} \pm 180^\circ & \text{if Type 0 and } dist < limit \end{cases} $$

## The Engineer's View
Controlled in `Rover::ParametersG2::loit_type`.
Affects path planning within `ModeLoiter`. If Type 1 is selected, the "Pivot Turn" logic may be triggered depending on the angle error.

## Tuning & Behavior
*   **Default Value:** 0 (Shortest path)
*   **Recommendation:**
    *   **Cars/Mowers:** Use **0**. It's the most efficient for battery life.
    *   **Boats:** Use **1** if your motor setup doesn't handle reverse well or if you want the boat to always face the wind/waves while loitering.