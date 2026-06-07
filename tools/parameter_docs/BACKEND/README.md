# Logging Backend (BACKEND)

## Overview
The **BACKEND** parameter group (specifically `BACKEND_TYPE`) configures the **AP_Logger** storage destinations. In the full parameter list, this is usually seen as `LOG_BACKEND_TYPE`.

## Key Concepts

### DataFlash Logging
ArduPilot records high-frequency flight data (IMU, EKF, GPS, Motors) to a "DataFlash" log (`.BIN` file). This log is essential for post-flight analysis and tuning.

### Backend Types
*   **File (1):** Standard SD Card logging.
*   **MAVLink (2):** Streams log data over the MAVLink telemetry link to the GCS (requires high bandwidth).
*   **Block (4):** Logs to onboard SPI Flash memory (common on smaller boards without SD slots).

## Parameter Breakdown

*   **`BACKEND_TYPE`**: Bitmask of active logging destinations.

## Integration Guide
*   **Standard:** Set to 1 (File) for most Pixhawk-class controllers.
*   **No SD Card:** Set to 4 (Block) if your board uses internal flash.