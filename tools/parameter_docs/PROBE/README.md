# Sensor Probing Configuration (PROBE)

## Overview
The **PROBE** parameter group (specifically `PROBE_EXT` or `BARO_PROBE_EXT`) configures the automatic hardware discovery for **External Sensors**.

## Key Concepts

### 1. I2C Probing
ArduPilot supports many different barometer and compass chips. Rather than forcing the user to select the exact chip model, the firmware can "probe" the I2C bus to see which chips respond.
*   **`PROBE_EXT`**: Defines which external I2C buses or specific addresses to scan during the boot sequence.

## Developer Notes
*   **Library:** `libraries/AP_Baro`, `libraries/AP_Compass`.
*   **Usage:** Usually left at default (Probe all) unless you have a specific hardware conflict.