---
layout: parameter
title: H_SW_COL_DIR
name: Swashplate Collective Control Direction
group: H
---

# H_SW_COL_DIR: Swashplate Collective Control Direction

## Description
Direction collective moves for positive pitch. 0 for Normal, 1 for Reversed.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Normal |
| 1 | Reversed |

## Description
This parameter controls the direction of collective pitch movement. It reverses the collective input to the swashplate mixing.

- **Normal (0):** Standard collective direction.
- **Reversed (1):** Inverted collective direction.

In the code, when set to **Reversed**, the collective input is inverted (`collective = 1 - collective`).

## Source Code
[ardupilot/libraries/AP_Motors/AP_MotorsHeli_Swash.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Swash.cpp)
