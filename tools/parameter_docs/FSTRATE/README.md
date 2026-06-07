# Fast Rate Threading (FSTRATE)

## Overview
The **FSTRATE** parameter group configures the **Fast-Rate Threading** architecture of the autopilot. This is an advanced performance feature for modern flight controllers (STM32F7 and H7).

## Key Concepts

### 1. Multi-Threaded Control
Standard autopilots run all tasks in a single loop. If a slow task (like writing to the SD card) takes too long, it can "starve" the critical attitude control loop, causing a jittery flight.
*   **Fast Rate Enable:** By setting `FSTRATE_ENABLE = 1`, the autopilot creates a separate, high-priority CPU thread dedicated *only* to the high-frequency control loops (Gyro -> PID -> Motors).

### 2. Stability
This ensures that no matter how busy the autopilot gets with telemetry or missions, the motors always receive their updates at a perfect, jitter-free frequency (e.g., exactly 400Hz or 800Hz).

## Parameter Breakdown

*   **`FSTRATE_ENABLE`**:
    *   **0:** Disabled (Single-threaded).
    *   **1:** Enabled (Dedicated high-priority loop).

## Developer Notes
*   **Library:** `AP_Scheduler`.
*   **Recommendation:** Highly recommended for all modern H7 boards (Orange Cube, Pixhawk 6X, etc.) to achieve the best possible flight feel.