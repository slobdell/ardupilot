# Waypoint Configuration (WP)

## Overview
The **WP** parameter group configures the high-level **Waypoint Navigation** logic.

## Key Concepts

### 1. Radius (`WP_RADIUS`)
Defines how close the vehicle must get to a waypoint before it is considered "Reached" and the vehicle moves to the next one.
*   **Too Small:** Vehicle may circle the waypoint indefinitely if it can't quite hit the target (e.g., in high wind).
*   **Too Large:** Vehicle will cut corners aggressively.

### 2. Facing Behavior (`WP_YAW_BEHAVIOR`)
Defines where the drone points its nose during autonomous flight.
*   **0:** None.
*   **1:** Face next waypoint.
*   **2:** Face direction of flight.

## Developer Notes
*   **Library:** `libraries/AP_Mission`.
*   **Related:** See [WPNAV](../WPNAV/README.md) for multicopter-specific path tuning.