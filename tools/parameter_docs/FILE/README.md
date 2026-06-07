# Log File Management (FILE)

## Overview
The **FILE** parameter group (often appearing as `LOG_FILE_` in the full parameter list) configures the low-level management of data logs stored on the **SD Card**.

These parameters ensure that the logging system does not crash the CPU during high-speed writes and that the SD card does not run out of space during a mission.

## Key Concepts

### 1. Write Buffering (`FILE_BUFSIZE`)
The autopilot writes data to a RAM buffer before flushing it to the SD card.
*   **Larger Buffer:** Smoother CPU performance, but more data is lost if the vehicle crashes/powers off before the buffer flushes.

### 2. Space Management (`FILE_MB_FREE`)
Ensures that the SD card is not filled to 100%. The autopilot will stop logging or delete old logs if the free space drops below this threshold.

### 3. Log Rotation (`FILE_DSRMROT`)
Determines when a new log file is created.
*   **Standard:** Create a new file every time the vehicle is Armed.

## Parameter Breakdown

*   **`FILE_BUFSIZE`**: Logging buffer size in kilobytes.
*   **`FILE_MB_FREE`**: Minimum free space (MB) to keep on the SD card.
*   **`FILE_RATEMAX`**: Limits the maximum frequency of writes to the file system.

## Developer Notes
*   **Library:** `libraries/AP_Logger/AP_Logger_File.cpp`.
*   **Performance:** High-speed logging (e.g., 400Hz IMU) requires a Class 10 or faster SD card.