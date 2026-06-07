---
layout: parameter
title: H_SW_LIN_SVO
name: Linearize Swashplate Servo Mechanical Throw
group: H
---

# H_SW_LIN_SVO: Linearize Swashplate Servo Mechanical Throw

## Description
This linearizes the swashplate servo's mechanical output to account for nonlinear output due to arm rotation. This requires a specific setup procedure to work properly. The servo arm must be centered on the mechanical throw at the servo trim position and the servo trim position kept as close to 1500 as possible. Leveling the swashplate can only be done through the pitch links. See the ardupilot wiki for more details on setup.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Enabled |

## Description
Enables compensation for the non-linear mechanical movement of rotary servo arms driving the swashplate. When enabled, it adjusts the servo output to produce linear swashplate movement relative to the input, provided the mechanical setup is correct (arms centered at 1500 trim).

## Source Code
[ardupilot/libraries/AP_Motors/AP_MotorsHeli_Swash.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Swash.cpp)
