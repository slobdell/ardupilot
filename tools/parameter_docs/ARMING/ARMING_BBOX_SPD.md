---
layout: parameter
name: ARMING_BBOX_SPD
display_name: Blackbox speed
description: This is a 3D GPS speed threshold above which we will force arm the vehicle to start logging. WARNING: This should only be used on a vehicle with no propellers attached to the flight controller and when the flight controller is not in control of the vehicle.
default_value: 5
range: 1 20
units: m/s
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/AP_Arming.cpp
---

# Blackbox speed (ARMING_BBOX_SPD)

## Description
GPS speed threshold for "Blackbox" mode, which automatically arms the flight controller to trigger data logging when a certain speed is reached.

## Tuning & Behavior
*   **Default Value:** 5 m/s
*   **Range:** 1 to 20 m/s
*   **Primarily used for high-speed logging on non-controlled platforms (e.g., as a dedicated logger).**
*   **WARNING: Do not use with propellers attached if the FC is not the primary controller.**