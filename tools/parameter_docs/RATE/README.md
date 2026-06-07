# Rate Loop Configuration (RATE)

## Overview
The **RATE** parameter group (specifically `RATE_ENABLE` or `FSTRATE_ENABLE`) configures the execution architecture of the high-speed **Attitude Rate Controllers**.

## Key Concepts

### 1. High-Priority Threading
Modern ArduPilot firmware can run the critical rate PID loops in a dedicated high-priority CPU thread.
*   **`RATE_ENABLE`**: Enables the fast-rate threading logic.
    *   **Benefit:** Ensures that motor updates are never delayed by lower-priority tasks like file I/O or MAVLink processing, resulting in a more stable and "locked-in" flight feel.

## Developer Notes
*   **Library:** `AP_Scheduler`.
*   **See Also:** [FSTRATE](../FSTRATE/README.md) for more details.