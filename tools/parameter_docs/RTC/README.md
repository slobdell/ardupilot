# Real-Time Clock Configuration (RTC)

## Overview
The **RTC** parameter group configures the **System Clock** management. Maintaining accurate UTC time is essential for logging, timestamping mission waypoints, and ensuring GNSS synchronization.

Since most flight controllers do not have a dedicated battery-backed clock chip, the autopilot must synchronize its time from external sources.

## Key Concepts

### 1. Time Sources (`RTC_TYPES`)
Defines which sources the autopilot is allowed to trust to set the time.
*   **Bit 0 (GPS):** The most accurate source. Sets time once a 3D lock is achieved.
*   **Bit 1 (MAVLink):** Receives time from the Ground Control Station.
*   **Bit 2 (Hardware):** Internal clock chip (if present).

### 2. Timezone (`RTC_TZ_MIN`)
Allows setting a local time offset (in minutes) for the OSD or logging.
*   **Note:** Internal logs are always kept in UTC; this only affects displayed time.

## Parameter Breakdown

*   **`RTC_TYPES`**: Bitmask of allowed sources.
*   **`RTC_TZ_MIN`**: Offset from UTC (minutes).

## Developer Notes
*   **Library:** `libraries/AP_RTC`.