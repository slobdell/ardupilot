# Data Injection Configuration (INJECT)

## Overview
The **INJECT** parameter group (specifically `INJECT_TO` or `GPS_INJECT_TO`) configures the routing of **RTK Correction** data.

## Key Concepts

### 1. RTK Routing
In a dual-GPS system, the RTK correction data (RTCM) arrives from the Ground Station over the telemetry link. The autopilot must decide which physical GPS receiver to send this data to.
*   **`INJECT_TO`**:
    *   **0:** Send to GPS 1.
    *   **1:** Send to GPS 2.
    *   **127:** Send to all connected GPS units.

## Developer Notes
*   **Library:** `libraries/AP_GPS`.
*   **Context:** Critical for centimeter-level positioning accuracy.