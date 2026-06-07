---
layout: parameter
title: POS_P
name: Winch control position error P gain
group: POS
---

# POS_P: Winch control position error P gain

## Description
Winch control position error P gain.

## Values
- **Range:** 0.01 to 10.0
- **Default:** 1.0

## Description
This parameter controls the responsiveness of the winch when moving to a specific cable length.

- **Function:** It converts the error between the desired cable length and the actual cable length into a desired deployment or retraction speed.
- **Formula:** $TargetRate = Error \times P_{gain}$
- **Tuning:**
    - **Higher Value:** Faster correction of length errors, but may cause oscillation or jerking if too high.
    - **Lower Value:** Slower, smoother approach to the target length.

## Source Code
[ardupilot/libraries/AP_Winch/AP_Winch.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Winch/AP_Winch.cpp#L34)

