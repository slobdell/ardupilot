---
layout: parameter
name: LOIT_RADIUS
display_name: Loiter radius
description: The distance from the target point within which the rover will consider itself "arrived" and allow for drifting or minimal correction.
default_value: 2
range: 0 20
units: m
group: LOIT
visual_asset_id: loiter_radius_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L349
---

# Loiter radius (LOIT_RADIUS)

## Description
`LOIT_RADIUS` is a **Rover-specific** parameter. It defines an "acceptance circle" around the loiter target.

Unlike a Multicopter (which tries to stay on a single pixel), a Rover (especially a Boat) often has to deal with currents or momentum that make perfect station-keeping difficult. `LOIT_RADIUS` creates a dead-zone where the Rover doesn't constantly fight small errors, saving battery and reducing mechanical wear on the steering/motors.

## The Mathematics
The error $e$ is the distance to target.
$$ \text{Correction} = \begin{cases} \text{PID}(e) & \text{if } e > \text{LOIT_RADIUS} \\ 0 & \text{if } e \leq \text{LOIT_RADIUS} \end{cases} $$
*(Note: Actual implementation uses a smoother blend, but this logic captures the intent).*

## The Engineer's View
In the Rover codebase, this is handled in `ModeLoiter`. It prevents "hunting" around the target point. For boats, this is often set to match the accuracy of the GPS or the length of the hull.

## Tuning & Behavior
*   **Default Value:** 2 meters
*   **Range:** 0 to 20 meters
*   **Recommendation:**
    *   **Boats:** Set to 5.0m or higher if in a current. This prevents the motor from constantly pulsing on and off.
    *   **Precision Rovers:** Set to 0.5m or 1.0m if using RTK GPS and you need tight positioning.
    *   **Sailboats:** This parameter is critical for "heaving-to" or staying within a start box.