---
layout: parameter
title: MAN_EXPO_PITCH
name: Manual input expo for pitch
group: MAN
---

# MAN_EXPO_PITCH: Manual input expo for pitch

## Description
Percentage exponential for pitch input in MANUAL, ACRO, and TRAINING modes.

## Values
- **Range:** 0 to 100
- **Units:** %
- **Increment:** 1
- **Default:** 0

## Description
This parameter adds exponential curvature ("expo") to the elevator stick input when flying in manual or semi-manual modes.

- **0%:** Linear response.
- **Higher %:** Reduces sensitivity around the neutral pitch stick position.
- **Benefit:** Helps prevent "porpoising" (pilot-induced oscillation in pitch) by making small elevator corrections less sensitive, while keeping full authority for loops and sharp turns.

## Source Code
[ardupilot/ArduPlane/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1253)

