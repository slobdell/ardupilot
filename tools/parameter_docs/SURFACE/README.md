# Surface Configuration (SURFACE)

## Overview
The **SURFACE** parameter group (specifically `SURFACE_DEPTH` or `BARO_SURFACE_DEPTH`) calibrates the depth reference for **ArduSub**.

## Key Concepts

### 1. Water Surface Reference
Submarines use pressure to calculate depth. However, atmospheric pressure changes.
*   **`SURFACE_DEPTH`**: The reading the pressure sensor gives when the ROV is at the water's surface.
*   **Calibration:** Usually set automatically by the GCS during the "Calibrate Pressure" step.

## Developer Notes
*   **Library:** `libraries/AP_Baro`.