---
layout: parameter
name: GPS_RAW_DATA
display_name: GPS Raw Data Logging
description: Enables logging of raw satellite observables for post-processing (PPK/RTK).
default_value: 0
range: 0 2
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp#L190
---

# GPS Raw Data Logging (GPS_RAW_DATA)

## Description
`GPS_RAW_DATA` enables the autopilot to record the raw satellite measurements (carrier phase, pseudorange) into the internal DataFlash log. 

This data is used for **Post-Processed Kinematics (PPK)**. If you need centimeter-level accuracy for mapping but don't have a real-time RTK link, you can record this raw data and use software (like RTKLIB) later to calculate an extremely precise flight path.

*   **0: Disabled.** Standard NMEA/Binary position data only.
*   **1: Enabled.** Logs raw data to the flight controller's SD card.
*   **2: Device Specific.** (Septentrio). Commands the GPS unit itself to start/stop its internal logging synchronized with vehicle arming.

## Tuning & Behavior
*   **Warning:** Raw GPS data creates very large log files. Ensure you have a fast, high-capacity SD card.
*   **Requirement:** Requires a GPS module that supports raw output (e.g. u-blox "P" or "F" series, or professional Septentrio/Trimble units).