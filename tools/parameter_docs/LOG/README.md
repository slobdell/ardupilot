# DataFlash Logging Configuration (LOG)

## Overview
The **LOG** parameter group configures the **DataFlash Logging** system. This is the "Black Box" of the autopilot, recording high-frequency internal data (IMU, PIDs, GPS, Battery) for post-flight analysis.

Logs are essential for tuning, diagnosing crashes, and verifying mission performance.

## Key Concepts

### 1. Storage Backend (`LOG_BACKEND_TYPE`)
Defines where the data is sent.
*   **File (1):** Records to the SD Card (Standard).
*   **MAVLink (2):** Streams logs to the Ground Station in real-time.
*   **Block (4):** Records to on-board SPI Flash memory.

### 2. Message Filter (`LOG_BITMASK`)
There are hundreds of data messages available. To save SD card space and CPU, you can choose which ones to log.
*   **Standard:** Logs basic navigation and attitude data.
*   **Fast Attitude:** Logs at the PID loop rate (essential for tuning).
*   **Raw IMU:** Logs every single gyro sample (very heavy, used for FFT analysis).

### 3. Disarmed Logging (`LOG_DISARMED`)
If enabled, the autopilot logs data even when the motors are not spinning. This is great for bench testing but consumes space quickly.

## Parameter Breakdown

*   **`LOG_BITMASK`**: Bitmask of active log categories.
*   **`LOG_BACKEND_TYPE`**: Output selection.
*   **`LOG_FILE_BUFSIZE`**: RAM buffer size.
*   **`LOG_MAX_FILES`**: Number of old logs to keep before overwriting.

## Integration Guide

### Diagnosing a Problem
1.  **Enable Raw Logging:** Set `LOG_BITMASK` to include `RawIMU` (check Wiki for exact bit for your version).
2.  **Replicate:** Fly and perform the maneuver that caused the issue.
3.  **Download:** Use the "DataFlash Logs" tab in Mission Planner to download the `.BIN` file.
4.  **Analyze:** Use "Review Log" to graph the data.

## Developer Notes
*   **Library:** `libraries/AP_Logger`.
*   **Speed:** On modern boards, logging can consume a significant portion of CPU time. Use `LOG_BITMASK` judiciously.