# Configuration Persistence (SAVE)

## Overview
The **SAVE** parameter group (specifically `SAVE_CFG` or `GPS_SAVE_CFG`) manages the non-volatile storage of external sensor settings.

## Key Concepts

### 1. Flash Synchronization
When the autopilot configures a peripheral (like a u-Blox GPS), those settings are lost when the GPS powers down unless a "Save" command is sent to the GPS's internal flash.
*   **`SAVE_CFG`**:
    *   **0:** Don't save. Autopilot re-configures the sensor on every boot.
    *   **1:** Save. Tells the sensor to store the current configuration permanently.

## Developer Notes
*   **Library:** `libraries/AP_GPS`.