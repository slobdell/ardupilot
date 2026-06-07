# Field Altitude Configuration (FIELD)

## Overview
The **FIELD** parameter group (specifically `FIELD_ELV` or `BARO_FIELD_ELV`) allows the user to provide a known reference altitude for the takeoff location.

## Key Concepts

### 1. Absolute Altitude Reference
By default, the barometer measures altitude relative to the pressure at the moment of arming (0m AGL). If the user knows the exact altitude above sea level (AMSL) of the field, they can enter it here to provide a more accurate absolute vertical reference for the EKF and Ground Control Station.

## Parameter Breakdown

*   **`FIELD_ELV`**: Known elevation of the takeoff point in meters above sea level.
    *   **0:** System attempts to determine origin altitude from GPS.

## Developer Notes
*   **Library:** `libraries/AP_Baro`.
*   **Persistence:** In many configurations, this parameter resets to 0 on reboot to prevent using an incorrect elevation at a different location.