---
layout: parameter
title: WIND_MAX
name: Maximum airspeed and ground speed difference
group: WIND
---

# WIND_MAX: Maximum airspeed and ground speed difference

## Description
If the difference between airspeed and ground speed is greater than this value the sensor will be marked unhealthy.

## Values
- **Range:** 0 to 100
- **Units:** m/s
- **Default:** 0

## Description
This parameter sets a sanity check for the airspeed sensor.

- **Logic:** The autopilot assumes that `Airspeed - GroundSpeed` roughly equals `Wind Speed`. If this difference exceeds `WIND_MAX`, it implies the wind is impossibly strong (e.g., a hurricane) or, more likely, the airspeed sensor is giving bad data (e.g., pitot tube blocked).
- **Effect:** If this threshold is breached, the EKF may declare the airspeed sensor unhealthy and stop using it for flight control.
- **0:** Disabled (No check).

## Source Code
[ardupilot/libraries/AP_Airspeed/AP_Airspeed.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Airspeed/AP_Airspeed.cpp#L140)
