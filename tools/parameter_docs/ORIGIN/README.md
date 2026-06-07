# Local Frame Origin (ORIGIN)

## Overview
The **ORIGIN** parameter group (specifically `ORIGIN_LAT`, `LON`, and `ALT`) defines the global anchor point for vehicles operating in a **Local Coordinate Frame**.

This is primarily used when flying **Indoors** or in GPS-denied environments using **Beacons** (Pozyx/Marvelmind) or **Visual Odometry**.

## Key Concepts

### 1. Anchoring the Local Map
Indoor positioning systems report position relative to a local origin (0,0,0). To allow the GCS to draw the drone on a world map, the autopilot must know where that (0,0,0) point is physically located on Earth.
*   **`ORIGIN_LAT` / `LON`**: The Geodetic coordinates of the local origin.
*   **`ORIGIN_ALT`**: The altitude (AMSL) of the local origin.

## Developer Notes
*   **Library:** `libraries/AP_Beacon`.
*   **Context:** Without these parameters, the vehicle can still hover and fly relative to its starting point, but it cannot perform mission-based navigation using global waypoints.