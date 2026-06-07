---
layout: parameter
name: MOT1_DIRECTION
display_name: Motor 1 Normal or Reverse
description: Used to change motor rotation direction without changing wires.
default_value: 1
range: -1 1
units: 
group: MOT
visual_asset_id: mot_direction_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_Motors6DOF.cpp#L34
---

# Motor 1 Normal or Reverse (MOT1_DIRECTION)

## Description
`MOT1_DIRECTION` allows you to reverse the spin direction of Motor 1 via software. This is useful for "Sub" (Submarine) vehicles or Rovers where rewiring is difficult.

*   **1: Normal.**
*   **-1: Reverse.**

## The Engineer's View
This parameter is primarily used by `AP_Motors6DOF` (Sub) and `AP_MotorsUGV` (Rover).
For Multicopters (Copter/QuadPlane), motor direction is usually fixed by the frame type and wiring, or reversed via DShot commands (`SERVO_BLH_REV`). This parameter might not have an effect on standard Copters unless using a specific frame class that supports it.

## Tuning & Behavior
*   **Default Value:** 1
*   **Usage:** Change to -1 if the motor is spinning the wrong way and you cannot swap two phase wires.