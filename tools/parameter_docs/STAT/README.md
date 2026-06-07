# Vehicle Statistics Configuration (STAT)

## Overview
The **STAT** parameter group configures the **Flight Statistics** tracking system. This system acts like an odometer for your drone, recording total flight time, number of boots, and total runtime across the life of the vehicle.

These values are stored in non-volatile memory and persist across firmware updates.

## Key Concepts

### 1. Lifetime Tracking
*   **`STAT_FLTTIME`**: Total accumulated time the vehicle has been in the air (seconds).
*   **`STAT_RUNTIME`**: Total time the flight controller has been powered on.
*   **`STAT_BOOTCNT`**: Number of times the flight controller has been rebooted.

### 2. Resets (`STAT_RESET`)
Allows the user to clear the statistics (e.g., after a major rebuild or when selling the airframe).
*   **Magic Number:** Usually requires a specific value to be written to prevent accidental resets.

## Parameter Breakdown

*   **`STAT_FLTTIME`**: Total flight time (seconds).
*   **`STAT_BOOTCNT`**: Boot counter.

## Developer Notes
*   **Library:** `libraries/AP_Stats`.
*   **Persistence:** Statistics are saved to the "Parameter Storage" area periodically and on disarm.