---
layout: parameter
title: ORIGIN_ALT
name: Backup altitude (MSL) for EKF origin
group: ORIGIN
---

# ORIGIN_ALT: Backup altitude (MSL) for EKF origin

## Description
Backup EKF origin altitude (Mean Sea Level) used when not using a positioning system.

## Values
- **Units:** m
- **Default:** 0

## Description
This parameter sets a fixed "Home" altitude for the EKF when no GPS or other absolute positioning system is available.

- **Usage:** Primarily used in **ArduSub** or indoor non-GPS environments where the vehicle needs a reference point to initialize its navigation filter.
- **Function:** If the EKF cannot find a global origin (e.g., via GPS lock), it will use this value (along with `ORIGIN_LAT` and `ORIGIN_LON`) to establish its local coordinate frame.

## Source Code
[ardupilot/ArduSub/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduSub/Parameters.cpp#L736)

