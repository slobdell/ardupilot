# Navigation Speed Configuration (SPEED)

## Overview
The **SPEED** parameter group (specifically `SPEED_MAX`) configures the horizontal travel speed for **ArduRover**.

## Key Concepts

### 1. Velocity Target
*   **`SPEED_MAX`**: The physical maximum speed (m/s) that the rover is capable of at full throttle.
*   **Estimation:** If set to 0, the autopilot will attempt to estimate the max speed based on `CRUISE_SPEED` and `CRUISE_THROTTLE`.

## Developer Notes
*   **Library:** `ArduRover/Parameters.cpp`.
*   **Related:** Multicopter navigation speeds are typically in the `WPNAV_` group.