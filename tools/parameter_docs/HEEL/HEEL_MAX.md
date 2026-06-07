---
layout: parameter
title: HEEL_MAX
name: Sailing maximum heel angle
group: HEEL
---

# HEEL_MAX: Sailing maximum heel angle

## Description
When in auto sail trim modes, the heel (roll angle) will be limited to this value using PID control.

## Values
- **Range:** 0 to 90
- **Units:** deg
- **Increment:** 1
- **Default:** 15

## Description
This parameter sets the safety limit for the sailboat's heel (tipping) angle. If the boat tilts more than this angle due to strong wind, the autopilot will automatically release the mainsheet (or depower the wingsail) to bring the boat back upright.

- **Primary Use:** Preventing capsize and reducing excessive weather helm (tendency to turn into the wind) which causes drag.
- **Mechanism:** The value acts as a setpoint for a PID controller in the Attitude Control library. When the actual heel exceeds `HEEL_MAX`, the controller calculates a "sheet out" value to reduce sail power.

## Source Code
[ardupilot/Rover/sailboat.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/sailboat.cpp#L67)
