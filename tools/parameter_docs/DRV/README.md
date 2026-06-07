# Driver Options (DRV)

## Overview
The **DRV** parameter group (specifically `DRV_OPTIONS` or `GPS_DRV_OPTIONS`) provides a mechanism to enable experimental features or workarounds for specific hardware drivers (primarily GPS).

## Key Concepts

### 1. Driver-Specific Flags
The meaning of the bits depends heavily on the specific GPS driver being used (u-Blox, SBP, NMEA).
*   **Examples:** Enable/Disable specific NMEA messages, change baud rate negotiation, or enable experimental constellations (Galileo/BeiDou) if the driver doesn't support a dedicated parameter for it.

## Parameter Breakdown

*   **`DRV_OPTIONS`**: Bitmask.

## Integration Guide
*   **Documentation:** Refer to the full parameter list for your specific firmware version to see what the bits do. It changes frequently.

## Developer Notes
*   **Library:** `libraries/AP_GPS`
*   **Scope:** Used inside `AP_GPS_uBlox.cpp`, etc.