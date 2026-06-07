# Turn Dynamics Configuration (TURN)

## Overview
The **TURN** parameter group configures the physical limits of the vehicle's turning capability.

## Key Concepts

### 1. Lateral Acceleration (`TURN_MAX_G`)
(Rover/Plane) Defines the maximum lateral force (in Gs) the vehicle is allowed to pull in a turn.
*   **Purpose:** Prevents high-speed tip-overs (Rover) or structural stress (Plane).

### 2. Turn Radius (`TURN_RADIUS`)
(Rover) The physical minimum turning circle of the vehicle at low speeds.
*   **Importance:** Used by the path planner to ensure waypoints are achievable.

## Developer Notes
*   **Library:** `libraries/AP_L1_Control`, `libraries/AR_AttitudeControl`.