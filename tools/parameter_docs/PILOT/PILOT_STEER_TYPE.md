---
layout: parameter
name: PILOT_STEER_TYPE
display_name: Pilot Steering Type
description: Selects the control scheme for manual steering on Rovers and Boats.
default_value: 0
range: 0 1
units: 
group: PILOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp#L107
---

# Pilot Steering Type (PILOT_STEER_TYPE)

## Description
`PILOT_STEER_TYPE` defines how your transmitter sticks move the Rover or Boat.

*   **0: Default.** The steering stick controls the vehicle's turn rate or wheel angle.
*   **1: Two-Paddle.** (Used for skid-steer). Left stick controls the left motor, right stick controls the right motor. This provides a direct, "old-school" tank control feel.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Use **0** for most vehicles, as it allows the autopilot to perform stabilization and speed control more effectively. Only use **1** if you are specifically trained on dual-throttle tank controls.