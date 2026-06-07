---
layout: parameter
name: SIM_SERVO_SPEED
display_name: Simulated Servo Speed
description: The time (in seconds) it takes for a simulated servo to move 60 degrees.
default_value: 0.11
range: 0.01 1.0
units: s/60deg
group: SIM
visual_asset_id: servo_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/ServoModel.cpp#L25
---

# Simulated Servo Speed (SIM_SERVO_SPEED)

## Description
`SIM_SERVO_SPEED` defines how fast the virtual servos move.

Real servos aren't instant. If you have a slow servo on a racing quad, the PID loop will oscillate because the motor doesn't reach the target speed fast enough. This parameter allows you to simulate that physical delay.

## Tuning & Behavior
*   **Default Value:** 0.11 s/60° (Standard hobby servo).
*   **High Performance:** Set to **0.05** for fast brushless servos.
*   **Large Drones:** Set to **0.20** for heavy-duty, slow servos.