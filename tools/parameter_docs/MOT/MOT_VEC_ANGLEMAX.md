---
layout: parameter
name: MOT_VEC_ANGLEMAX
display_name: Vector Thrust Angle Max
description: The maximum mechanical tilt angle (in degrees) for steerable boat motors.
default_value: 0
range: 0 90
units: deg
group: MOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_Motors/AP_MotorsUGV.cpp#L112
---

# Vector Thrust Angle Max (MOT_VEC_ANGLEMAX)

## Description
`MOT_VEC_ANGLEMAX` defines the mechanical limit of your boat's steerable motor. 

Unlike a rudder, which is a passive fin, **Vectored Thrust** means the entire motor or propeller unit rotates to steer the boat. This parameter tells the autopilot how many degrees of physical rotation your motor mount can achieve.

## Tuning & Behavior
*   **Default:** 0.
*   **Action:** Measure the maximum angle your motor can physically pivot to the left or right. If the motor can turn 30 degrees in each direction, set this to **30**.
*   **Note:** This is only used for Boat frames where the motor itself is the steering actuator.