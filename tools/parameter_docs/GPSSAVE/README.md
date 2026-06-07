# GPS Configuration Storage (GPSSAVE)

## Overview
The **GPSSAVE** parameter group (specifically `GPS_SAVE_CFG`) manages the persistence of configuration commands sent from ArduPilot to the GPS receiver.

## Key Concepts

### 1. Boot-time Configuration
At startup, ArduPilot sends a series of commands to u-Blox receivers to set the baud rate, update rate (5Hz/10Hz), and enabled constellations.
*   **`GPS_SAVE_CFG`**:
    *   **0:** Don't save. Autopilot configures the GPS on every boot.
    *   **1:** Save. Autopilot configures the GPS once and tells it to save those settings to its internal non-volatile memory (Flash).

## Developer Notes
*   **Library:** `libraries/AP_GPS`.