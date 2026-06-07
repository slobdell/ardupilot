# External Bus Configuration (EXT)

## Overview
The **EXT** parameter group (specifically `EXT_BUS`) defines the hardware bus assignment for **External Sensors**.

## Key Concepts

### 1. External Bus Selection
When using sensors that are not built-in to the flight controller (e.g., an external I2C Barometer or Compass), the autopilot needs to know which physical I2C bus to probe.
*   **Pixhawk/Cube:** Usually Bus 1 (External 1) or Bus 2 (Internal).
*   **`EXT_BUS`**: Manually overrides the autodetection if a sensor is plugged into a non-standard port.

## Parameter Breakdown

*   **`EXT_BUS`**: I2C Bus ID (0, 1, 2, 3).
    *   **-1:** Autodetect (Standard behavior).

## Developer Notes
*   **Library:** `libraries/AP_Baro` (often aliased as `BARO_EXT_BUS`).