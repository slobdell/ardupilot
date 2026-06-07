---
layout: parameter
name: STICK_MIXING
display_name: "Stick Mixing"
description: "Allows the pilot to nudge the vehicle's position or attitude during autonomous flight modes without changing modes."
default_value: 1
range: 0 3
units: "Option"
group: STICK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L109
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Stick Mixing (STICK_MIXING)

## Description
This parameter enables "Manual Nudging" during autonomous flight modes (like AUTO, GUIDED, or RTL). It allows the pilot to use the transmitter sticks to temporarily override the autopilot's path without actually taking full manual control.

This is a vital safety and utility feature. For example, if a drone is landing autonomously but the pilot sees an obstacle on the ground, they can nudge the stick to shift the landing spot slightly while the autopilot continues to handle the descent and stabilization.

## The Mathematics
The autopilot combines the navigation command ($Cmd_{nav}$) with the pilot's stick input ($Input_{pilot}$):

**FBW Mixing (Mode 1):**
The stick input is treated as a delta to the target attitude.
$$ \text{TargetAngle} = \text{TargetAngle}_{nav} + (Input_{pilot} \times \text{MaxAngle}) $$

**VTOL Yaw (Mode 3):**
Specifically applies only to the Yaw axis during QuadPlane VTOL phases.
$$ \text{YawRate} = \text{YawRate}_{nav} + (Input_{yaw\_stick} \times \text{MaxYawRate}) $$

## The Engineer's View
In `ArduPlane/Attitude.cpp`, the function `Plane::stick_mixing_enabled()` checks this parameter.
*   **Mode 0 (None):** Sticks are ignored in Auto modes. **Danger:** If the GPS glitches, the pilot has no way to "steer" the plane without first flipping a switch to a manual mode.
*   **Mode 1 (FBW):** Uses "Fly-By-Wire" logic. This is the recommended setting. It ensures that the pilot can never command an unsafe bank or pitch angle, even while nudging.
*   **Mode 3 (VTOL Yaw):** Used for QuadPlanes to allow the pilot to point the nose of the aircraft during an automatic VTOL takeoff or landing while the autopilot maintains position.

## Tuning & Behavior
*   **Default Value:** 1 (FBW).
*   **Recommendation:** Keep at **1** for most users. It provides the best balance of autonomous precision and pilot authority.
*   **Rover:** On Rovers, this allows the pilot to steer around obstacles on a mission path. The rover will return to the direct line to the waypoint once the pilot releases the stick.

