---
layout: parameter
title: HGT_OVR
name: Height override of sensor above ground
group: HGT
---

# HGT_OVR: Height override of sensor above ground

## Description
This is used in rover vehicles where the sensor is a fixed height above the ground.

## Values
- **Range:** 0 to 2
- **Units:** m
- **Increment:** 0.01
- **Default:** 0.0f

## Description
For Rovers using an Optical Flow sensor, this parameter tells the autopilot exactly how high the sensor is mounted above the ground.

- **Why it matters:** Optical flow sensors measure how fast the texture of the ground moves across their view (angular velocity). To convert this into actual vehicle speed (linear velocity), the autopilot must know the distance to the ground.
- **Calculation:** $Velocity = FlowRate \times Height$.
- **Rover vs. Copter:** Copters use a rangefinder (Lidar/Sonar) because their height changes. Rovers stay on the ground, so a fixed value can be used instead of a rangefinder.

## Source Code
[ardupilot/libraries/AP_OpticalFlow/AP_OpticalFlow.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OpticalFlow/AP_OpticalFlow.cpp#L105)

