---
layout: parameter
name: SERVO_PITCH_TYPE
display_name: Pitch Servo Actuator Type
description: Selects between proportional position servos or discrete on/off actuators for the pitch axis.
default_value: 0
range: 0 1
units: 
group: SERVO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L96
---

# Pitch Servo Actuator Type (SERVO_PITCH_TYPE)

## Description
`SERVO_PITCH_TYPE` defines the control hardware used for an **Antenna Tracker's** vertical axis.

*   **0: Position Servo.** Standard proportional RC servo. The autopilot commands a specific angle.
*   **1: On/Off Actuator.** A simple motor or relay. The autopilot "pulses" the motor based on [ONOFF_PITCH_RATE](ONOFF_PITCH_RATE.html) to reach the target angle.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Only change to **1** if you are using a heavy-duty antenna tracker with industrial motor drivers that do not support standard PWM servo signals.