---
layout: parameter
title: INITIAL_MODE
name: Initial driving mode
group: INITIAL
---

# INITIAL_MODE: Initial driving mode

## Description
This selects the mode to start in on boot. This is useful for when you want to start in AUTO mode on boot without a receiver. Usually used in combination with when `AUTO_TRIGGER_PIN` or `AUTO_KICKSTART`.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Manual |
| 1 | Acro |
| 3 | Steering |
| 4 | Hold |
| 5 | Loiter |
| 6 | Follow |
| 7 | Simple |
| 8 | Dock |
| 9 | Circle |
| 10 | Auto |
| 11 | RTL |
| 12 | SmartRTL |
| 15 | Guided |

- **Default:** 0 (Manual)

## Description
This parameter determines the vehicle's state immediately after the flight controller boots up.

- **Standard Use:** Keep at **0 (Manual)** for normal operations where you turn on the rover and then switch modes using your RC transmitter.
- **Autonomous/No-RC Use:** Set to **10 (Auto)** if you want the rover to immediately begin a mission upon power-up (often used with `AUTO_TRIGGER_PIN` to require a button press, or `AUTO_KICKSTART` to require a push before the motor engages).

## Source Code
[ardupilot/Rover/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L34)

