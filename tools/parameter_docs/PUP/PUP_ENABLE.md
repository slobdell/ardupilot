---
layout: parameter
title: PUP_ENABLE
name: Enable pullup after altitude wait
group: PUP
investigation_status: complete
---

# PUP_ENABLE: Enable pullup after altitude wait

## Description
Enable pullup after altitude wait.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Enabled |

- **Default:** 0

## Description
This parameter activates the special "Pull-Up" sequence for high-altitude glider drops (e.g., from a balloon).

- **Function:** When the mission command `NAV_ALTITUDE_WAIT` completes (meaning the balloon has burst or the release altitude is reached), the plane will execute a controlled pull-up maneuver to transition from a vertical dive to level flight without over-stressing the airframe.
- **Safety:** Prevents structural failure by limiting the G-force (`PUP_NG_LIM`) during the recovery.

## Source Code
[ardupilot/ArduPlane/pullup.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/pullup.cpp#L16)

