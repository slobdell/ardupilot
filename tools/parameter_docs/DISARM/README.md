# Auto Disarm Configuration (DISARM)

## Overview
The **DISARM** parameter group (specifically `DISARM_DELAY`) configures the automatic disarming safety feature.

If the vehicle is Armed but the motors are at idle (throttle zero) and the vehicle is not moving (landed), the autopilot will automatically disarm itself after a set timeout. This prevents injury if the pilot approaches the vehicle forgetting it is still live.

## Key Concepts

### 1. Landed State Detection
The timer only starts counting when the autopilot is confident it is **Landed**. This requires consistent low throttle and low accelerometer variance.

### 2. Delay Timer
*   **`DISARM_DELAY`**: Time in seconds.
    *   **0:** Disabled (Will never auto-disarm).
    *   **10 (Default):** Disarms after 10 seconds of idle on the ground.

## Parameter Breakdown

*   **`DISARM_DELAY`**: Timeout (seconds).

## Integration Guide
*   **Safety:** Keep this enabled (10s or 15s) for all vehicles.
*   **Exception:** For long-endurance loiter on the ground (e.g., waiting for GPS), you might disable it, but use the Safety Switch instead.

## Developer Notes
*   **Vehicle:** All (Copter, Plane, Rover).
*   **Logic:** Managed by the `AP_Motors` or vehicle main loop.