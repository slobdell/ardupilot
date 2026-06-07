---
layout: parameter
title: PHLD_BRAKE_RATE
name: PosHold braking rate
group: PHLD
---

# PHLD_BRAKE_RATE: PosHold braking rate

## Description
PosHold flight mode's rotation rate during braking in deg/sec.

## Values
- **Range:** 4 to 12
- **Units:** deg/s
- **Default:** 8

## Description
This parameter controls how quickly the drone rotates to the braking angle when stopping in **PosHold** mode.

- **Function:** When you release the sticks, the drone needs to pitch backwards to stop. This parameter limits how fast that pitch rotation happens.
- **Higher Value:** Snappier braking action. The drone rotates quickly to the braking angle.
- **Lower Value:** Smoother onset of braking. The drone rotates slowly to the braking angle.

## Source Code
[ardupilot/ArduCopter/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L364)

