---
layout: parameter
title: PRX_MAX_RATE
name: Proximity Sensor max rate
group: PRX
---

# PRX_MAX_RATE: Proximity Sensor max rate

## Description
This is the maximum rate we send Proximity Sensor data in Hz. Zero means no limit.

## Values
- **Range:** 0 to 200
- **Units:** Hz
- **Default:** 50

## Description
This parameter limits the frequency of proximity data messages sent by the AP_Periph device.

- **Purpose:** Prevents high-speed Lidar sensors from flooding the CAN bus or telemetry link with too much data.
- **50Hz (Default):** A good balance for obstacle avoidance.
- **0:** Sends data as fast as the sensor can read (can be >1000Hz for some Lidars, which may choke the bus).

## Source Code
[ardupilot/Tools/AP_Periph/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L572)

