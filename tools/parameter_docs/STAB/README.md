# Stabilization Options (STAB)

## Overview
The **STAB** parameter group (specifically `STAB_PITCH_DOWN`) configures the assisted flight behaviors in **Stabilize** and **FBWA** modes.

## Key Concepts

### 1. Low Throttle Pitch Trim
In a manual airplane, reducing throttle typically causes the nose to drop as airspeed decreases. In an autopilot-stabilized mode, the autopilot might try to hold the nose up, which can lead to a stall.
*   **`STAB_PITCH_DOWN`**: Automatically adds a small amount of down-elevator (pitch down) when the throttle is at zero or idle.
    *   **Purpose:** Keeps the nose down in a glide to maintain airspeed and prevent stall.
    *   **Typical Value:** 2 to 5 degrees.

## Developer Notes
*   **Library:** `ArduPlane/Parameters.cpp`.
*   **Context:** Only relevant for **ArduPlane**.