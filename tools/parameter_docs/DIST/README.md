# Distance Limits (DIST)

## Overview
The **DIST** parameter group (specifically `DIST_MAX`) acts as a simple **Geofence** radius limit for some vehicle types (primarily Rover).

## Key Concepts

### 1. Distance from Home
Limits how far the vehicle can travel from the Home position (Arming location).
*   **Action:** If the limit is breached, the vehicle typically triggers RTL (Return to Launch) or stops.

## Parameter Breakdown

*   **`DIST_MAX`**: Maximum allowed distance from Home (meters).
    *   **0:** Disabled.

## Integration Guide
*   **Simple Safety:** Useful for keeping a rover within RC range without setting up complex polygon fences.

## Developer Notes
*   **Vehicle:** **ArduRover**.
*   **Note:** Plane and Copter typically use the full `FENCE_` library instead.