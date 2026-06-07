# GPS Blending (GPSBLEND)

## Overview
The **GPSBLEND** parameter group (specifically `GPS_BLEND_MASK`) configures the dual-GPS blending engine.

Unlike switching, which picks one GPS, **Blending** takes the data from both units and creates a single, mathematical "best" solution. This typically results in less position "jump" and smoother flight paths in areas with multi-path interference (e.g., near buildings).

## Key Concepts
See the [BLEND](../BLEND/README.md) group documentation for a detailed breakdown of the weighting mathematics and bitmask configuration.

## Developer Notes
*   **Library:** `libraries/AP_GPS/AP_GPS_Blended.cpp`.