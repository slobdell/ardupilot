# GPS Raw Logging (GPSRAW)

## Overview
The **GPSRAW** parameter group (specifically `GPS_RAW_DATA`) controls the logging of low-level satellite measurements.

## Key Concepts

### 1. RAW Measurement Logging
Normally, ArduPilot only logs the finished position (Lat/Lon). If `GPS_RAW_DATA` is enabled, the autopilot logs the raw pseudorange and doppler data for every satellite.
*   **Purpose:** Required for **PPK (Post-Processed Kinematics)** mapping, where you process the flight logs later with a base station log to get centimeter-level accuracy without a live RTK link.

## Developer Notes
*   **Log Message:** `GPA` and `GPS` messages are supplemented by raw binary streams.