# Automatic Identification System (AIS)

## Overview
The **AIS** parameter group configures the **Marine AIS** subsystem. This is the nautical equivalent of ADS-B. It allows ArduRover (Boat) to detect nearby commercial vessels equipped with AIS transmitters.

## Key Concepts

### 1. Collision Avoidance
AIS data is fed into the **AVOID** library. If a vessel is detected on a collision course, the autopilot can warn the operator or autonomously steer away (if avoidance is configured).

### 2. Hardware
Typically requires a serial AIS receiver connected to a UART port.

## Parameter Breakdown

*   **`AIS_TYPE`**: 0=Disabled, 1=NMEA (Standard Serial AIS).
*   **`AIS_TIME_OUT`**: Time (seconds) without a signal before a vessel is considered lost/gone.
*   **`AIS_LIST_MAX`**: Maximum number of vessels to track in memory.

## Integration Guide
1.  **Hardware:** Connect NMEA 0183 AIS Receiver to a Serial Port.
2.  **Serial Config:** Set `SERIALx_PROTOCOL = 40` (AIS). Baud rate usually 38400.
3.  **Enable:** Set `AIS_TYPE = 1`.

## Developer Notes
*   **Library:** `libraries/AP_AIS`
*   **Vehicle:** **ArduRover** (Boats).