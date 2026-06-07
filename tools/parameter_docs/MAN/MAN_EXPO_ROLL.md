---
layout: parameter
title: MAN_EXPO_ROLL
name: Manual control expo for roll
group: MAN
---

# MAN_EXPO_ROLL: Manual control expo for roll

## Description
Percentage exponential for roll input in MANUAL, ACRO, and TRAINING modes.

## Values
- **Range:** 0 to 100
- **Units:** %
- **Increment:** 1
- **Default:** 0

## Description
This parameter adds exponential curvature ("expo") to the aileron stick input when flying in manual or semi-manual modes.

- **0%:** Linear response. 50% stick = 50% servo travel.
- **Higher %:** Reduces sensitivity around the center stick position (neutral) while maintaining full throw at the extremes.
- **Benefit:** Allows for smoother fine-control adjustments during level flight while still permitting aggressive maneuvers when the stick is pushed fully.

## Source Code
[ardupilot/ArduPlane/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1245)

