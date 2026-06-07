# Jerk Limit Configuration (JERK)

## Overview
The **JERK** parameter group (often appearing as `PSC_JERK_` in the full parameter list) configures the smoothness of the vehicle's motion.

"Jerk" is the rate of change of acceleration (the 3rd derivative of position). By limiting jerk, the autopilot ensures that the vehicle doesn't "snap" its movements, resulting in a more fluid, organic, and cinematographic flight feel.

## Key Concepts

### 1. Motion Kinematics
*   **Velocity:** Speed.
*   **Acceleration:** How fast speed changes.
*   **Jerk:** How fast acceleration changes.

### 2. S-Curve Path Planning
ArduPilot uses **S-Curves** for navigation. S-Curves ensure that velocity increases and decreases smoothly by strictly controlling the jerk levels.
*   **`JERK_XY`**: Horizontal jerk limit.
*   **`JERK_Z`**: Vertical jerk limit.

## Parameter Breakdown

*   **`JERK_XY`**: Maximum horizontal jerk (m/s/s/s).
    *   **Higher values:** Snappier, more aggressive waypoint turns.
    *   **Lower values:** Smoother, smoother starts and stops.

## Integration Guide
*   **Cinematography:** Decrease these values for ultra-smooth pans and steady shots.
*   **Racing/Agility:** Increase these values to allow the drone to "snap" onto its new heading/velocity quickly.

## Developer Notes
*   **Library:** `libraries/AC_PrecLand`, `libraries/AR_AttitudeControl`, and `AC_PosControl`.
*   **Constraint:** These parameters limit the output of the position controller's path generator.