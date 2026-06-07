---
layout: parameter
title: PHLD_BRAKE_ANGLE
name: PosHold braking angle max
group: PHLD
---

# PHLD_BRAKE_ANGLE: PosHold braking angle max

## Description
PosHold flight mode's max lean angle during braking in centi-degrees.

## Values
- **Range:** 2000 to 4500
- **Units:** cdeg
- **Default:** 3000 (30 degrees)

## Description
This parameter sets the maximum tilt angle the drone will use to stop when you release the sticks in **PosHold** mode.

- **PosHold Mode:** Unlike Loiter (where the stick controls velocity), PosHold feels like Stabilize (stick controls angle) but stops and holds position when you let go.
- **Higher Value:** Faster stopping, but more aggressive pitch-back motion.
- **Lower Value:** Gentler, smoother stops, but takes more distance to come to a halt.

## Source Code
[ardupilot/ArduCopter/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L373)

