# Disarmed Logging Configuration (DARM)

## Overview
The **DARM** parameter group (specifically `DARM_RATEMAX`) manages the behavior of the **AP_Logger** system when the vehicle is **Disarmed**.

Normally, high-frequency logging is only required during flight. However, it is often useful to log data while on the ground (for debugging GPS health, sensor noise, or configuration issues). This parameter prevents the log file from growing massively while the drone sits idle.

## Key Concepts

### 1. Rate Limiting
Instead of logging IMU data at 400Hz or GPS data at 10Hz, the logger can be throttled down to a lower frequency (e.g., 1Hz or 5Hz) while disarmed.

## Parameter Breakdown

*   **`DARM_RATEMAX`**: The maximum frequency (Hz) for logging messages while disarmed.
    *   **0:** No limit (Logs at full speed if `LOG_DISARMED` is enabled).
    *   **>0:** Limits logging to this rate.

## Integration Guide
*   **Debug:** Set `DARM_RATEMAX = 0` and `LOG_DISARMED = 1` if you are diagnosing sensor issues on the bench.
*   **Normal:** Keep at default or set to a low value (e.g., 5Hz) to save SD card space if you leave `LOG_DISARMED` on.

## Developer Notes
*   **Library:** `libraries/AP_Logger`
*   **Logic:** Acts as a gatekeeper in the `Write_*` methods of the logger.