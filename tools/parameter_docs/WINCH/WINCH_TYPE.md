---
layout: parameter
title: WINCH_TYPE
name: Winch Type
group: WINCH
---

# WINCH_TYPE: Winch Type

## Description
Selects the type of winch hardware connected to the vehicle.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | None (Disabled) |
| 1 | PWM (Servo/ESC controlled) |
| 2 | Daiwa (Specific serial protocol) |

- **Default:** 0

## Description
This parameter enables the Winch library for package delivery or tether management.

- **PWM (1):** Allows control of a generic continuous rotation servo or ESC-driven motor using the `WINCH_` parameters.
- **Daiwa (2):** Enables support for the Daiwa winch protocol.

## Source Code
[ardupilot/libraries/AP_Winch/AP_Winch.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Winch/AP_Winch.cpp#L19)
