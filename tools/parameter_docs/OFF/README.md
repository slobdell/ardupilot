# Offset Calibration Checks (OFF)

## Overview
The **OFF** parameter group (specifically `OFF_PCNT` or `ARSPD_OFF_PCNT`) configures the safety checks for **Airspeed Sensor Calibration**.

## Key Concepts

### 1. Large Offset Warning
When you calibrate an airspeed sensor (zero the pressure), the autopilot compares the new zero-offset against the previous one.
*   **`OFF_PCNT`**: If the difference would cause a change in reported airspeed greater than this percentage (relative to `AIRSPEED_MIN`), a warning is issued.
*   **Purpose:** Detects if you accidentally calibrated while the pitot tube was uncovered in a breeze, which would lead to dangerous airspeed errors in flight.

## Developer Notes
*   **Library:** `libraries/AP_Airspeed`.