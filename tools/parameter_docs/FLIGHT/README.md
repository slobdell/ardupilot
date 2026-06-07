# Flight Options (FLIGHT)

## Overview
The **FLIGHT** parameter group (specifically `FLIGHT_OPTIONS`) is a high-level bitmask that enables or modifies miscellaneous flight behaviors across different vehicle types.

This is often a "catch-all" for options that don't belong to a specific sensor or flight mode.

## Key Concepts

### 1. Flight Options Bitmask
The bits in this parameter toggle experimental or non-standard behaviors.
*   **Examples (Variable by Vehicle):**
    *   Force arming even if some checks are failing (Advanced/Dangerous).
    *   Enable specific MAVLink status reporting.
    *   Alter behavior of the GCS failsafe.

## Parameter Breakdown

*   **`FLIGHT_OPTIONS`**: Bitmask.

## Integration Guide
*   **Recommendation:** Leave at 0 (Default) unless you are looking for a specific feature documented in the ArduPilot Wiki (e.g., "Set bit 5 of FLIGHT_OPTIONS to enable X").

## Developer Notes
*   **Library:** `AP_Vehicle` / `libraries/AP_Common`.