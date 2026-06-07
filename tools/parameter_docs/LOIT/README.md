# Loiter Mode Configuration (LOIT)

## Overview
The **LOIT** parameter group configures the behavior of the **Loiter** flight mode. Loiter is the standard GPS-based position-hold mode where the vehicle maintains its location and altitude when the sticks are centered.

Unlike "AltHold," which only holds height, Loiter uses the GPS and EKF to resist wind drift and maintain a fixed point over the ground.

## Key Concepts

### 1. Responsiveness (`LOIT_SPEED` / `LOIT_ACC_MAX`)
Defines how fast the drone moves when you push the sticks.
*   **`LOIT_SPEED`**: Maximum horizontal speed (cm/s).
*   **`LOIT_ACC_MAX`**: Maximum acceleration (cm/s/s). Lower values result in smoother, more cinematic movement.

### 2. Braking Aggression (`LOIT_BRK_...`)
Configures how the drone stops when the sticks are released.
*   **`LOIT_BRK_ACCEL`**: The deceleration rate.
*   **`LOIT_BRK_DELAY`**: The time (seconds) to wait before applying the brakes.

### 3. Turning (`LOIT_ANG_MAX`)
Limits the maximum lean angle used to maintain position. This is usually lower than the global `ANGLE_MAX` to prevent aggressive corrections.

## Parameter Breakdown

*   **`LOIT_SPEED`**: Top speed in cm/s (e.g., 1250 = 12.5 m/s).
*   **`LOIT_RADIUS`**: The circle radius used for loitering (Plane only).

## Integration Guide
*   **Cinematography:** Reduce `LOIT_ACC_MAX` to 250 and `LOIT_BRK_JERK` to 250 for very smooth transitions.
*   **Wind Performance:** If the drone drifts in high wind, ensure `LOIT_ANG_MAX` is high enough to lean into the wind.

## Developer Notes
*   **Library:** `ArduCopter/mode_loiter.cpp`.
*   **EKF:** Loiter is entirely dependent on a healthy EKF position estimate. If GPS is lost, the vehicle will usually switch to AltHold.