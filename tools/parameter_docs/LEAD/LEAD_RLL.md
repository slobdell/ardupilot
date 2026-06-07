---
layout: parameter
title: LEAD_RLL
name: Mount Roll stabilization lead time
group: LEAD
---

# LEAD_RLL: Mount Roll stabilization lead time

## Description
Servo mount roll angle output leads the vehicle angle by this amount of time based on current roll rate. Increase until the servo is responsive but does not overshoot.

## Values
- **Range:** 0.0 to 0.2
- **Units:** s
- **Increment:** 0.005
- **Default:** 0.0f

## Description
This parameter is a feed-forward term for the camera mount's roll stabilization. It helps compensate for servo lag during rolling maneuvers.

- **How it works:** It uses the vehicle's current roll *rate* (degrees per second) to predict where the roll angle will be in `LEAD_RLL` seconds and drives the servo to that future position immediately.
- **Tuning:** 
    - **Too Low:** The camera mount reacts too slowly to vehicle roll changes.
    - **Too High:** The camera mount over-corrects or jitters.

## Source Code
[ardupilot/libraries/AP_Mount/AP_Mount_Params.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Mount/AP_Mount_Params.cpp#L145)

