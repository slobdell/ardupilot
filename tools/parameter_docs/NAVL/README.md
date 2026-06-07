# L1 Navigation Controller (NAVL)

## Overview
The **NAVL** parameter group configures the **L1 Navigation Controller**. This is the core horizontal path-following algorithm used by **ArduPlane** and **ArduRover**.

The L1 controller is responsible for steering the vehicle to follow a straight line between waypoints or to maintain a perfect orbit during a loiter. It is known for its ability to handle high-speed flight and varying ground speeds (wind) with high precision.

## Key Concepts

### 1. The L1 Distance
The algorithm "looks ahead" along the path to a point at a specific distance (the L1 distance). It then calculates the lateral acceleration required to steer the vehicle toward that look-ahead point.
*   **`NAVL1_PERIOD`**: This is the primary tuning parameter. It defines the "Time" it should take to correct a path error.
    *   **Higher Period (e.g., 25s):** Softer, lazier tracking. Good for stable, slow planes.
    *   **Lower Period (e.g., 15s):** Aggressive, sharp tracking. Required for fast planes or rovers that need to stick to a tight path.

### 2. Damping (`NAVL1_DAMPING`)
Adjusts the "settling" behavior of the controller.
*   **0.75 (Default):** Standard critical damping.
*   **Increase:** If the vehicle overshoots the line and then oscillates.

## Parameter Breakdown

*   **`NAVL1_PERIOD`**: Path following aggression (seconds).
*   **`NAVL1_XTRACK_I`**: Integrator gain for correcting persistent crosstrack errors (e.g., in a strong crosswind).
*   **`NAVL1_LIM_BANK`**: Max bank angle used for navigation.

## Integration Guide
*   **Rover Tuning:** Rovers typically require a much lower `NAVL1_PERIOD` (e.g., 5-8s) than planes to handle sharp corners.
*   **Plane Tuning:** If your plane "S-turns" (weaves) back and forth across the mission line, **increase** the `NAVL1_PERIOD`.

## Developer Notes
*   **Library:** `libraries/AP_L1_Control`.
*   **Algorithm:** Nonlinear guidance law that produces a centripetal acceleration command.