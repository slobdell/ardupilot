# GPS Data Injection (GPSINJECT)

## Overview
The **GPSINJECT** parameter group configures the **RTK (Real-Time Kinematic)** data injection system.

For centimeter-level accuracy, a Ground Control Station (GCS) or fixed Base Station calculates atmospheric corrections and "injects" them into the vehicle's GPS receiver via the telemetry link.

## Key Concepts

### 1. Injection Target (`GPS_INJECT_TO`)
Defines which GPS instance (1 or 2) receives the RTK correction data.
*   **0:** GPS 1.
*   **1:** GPS 2.
*   **127:** All GPS units.

## Developer Notes
*   **Library:** `libraries/AP_GPS`.
*   **Protocol:** RTCM3 (Standard) or u-Blox MGA.