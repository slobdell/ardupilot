---
layout: parameter
name: TURN_RADIUS
display_name: "Turn radius of vehicle"
description: "Minimum turn radius of the rover in meters"
default_value: 0.9
range: 0 10
units: "m"
group: TURN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L454
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.h#L324
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Turn radius of vehicle (TURN_RADIUS)

## Description
This parameter defines the **Physical Minimum Turn Radius** of the rover at low speeds. It is a critical constraint for the navigation path planner (L1 controller). The autopilot uses this value to ensure it does not attempt turns sharper than the vehicle is mechanically capable of making, which would result in large crosstrack errors.

## The Mathematics
Used to clamp lateral acceleration demand:
$$ a_{lat_{max}} = \frac{V^2}{\text{TURN_RADIUS}} $$
(Simplified relation for limiting path curvature).

## The Engineer's View
Defined in `Rover/Parameters.cpp`.
*   **Skid Steering:** Even though skid steer vehicles can turn in place (Radius = 0), setting a non-zero value here (e.g., 0.5m) helps produce smoother, flowing turns during waypoint missions rather than stopping and pivoting.
*   **Ackermann Steering:** Must be set to the actual mechanical limit (plus a safety margin).

## Tuning & Behavior
*   **Default Value:** 0.9 m
*   **Procedure:** Drive the rover in a full lock circle manually, measure the radius, and enter that value here.