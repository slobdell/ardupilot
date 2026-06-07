---
layout: parameter
title: ORIENT_YAW
name: Beacon systems rotation from north in degrees
group: ORIENT
---

# ORIENT_YAW: Beacon systems rotation from north in degrees

## Description
Beacon systems rotation from north in degrees.

## Values
- **Range:** -180 to +180
- **Units:** deg
- **Increment:** 1
- **Default:** 0

## Description
This parameter aligns the coordinate system of your Indoor Positioning System (Beacons) with the autopilot's heading.

- **Usage:** If your beacon system's "North" (Y-axis) is not aligned with True North, use this parameter to rotate the beacon frame so that the autopilot flies in the correct direction.
- **Example:** If your beacon system's X-axis points East, but you want it to point North, you would adjust this value.

## Source Code
[ardupilot/libraries/AP_Beacon/AP_Beacon.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.cpp#L79)

