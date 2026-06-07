# No-Go Zone Configuration (NO)

## Overview
The **NO** parameter group (specifically `NO_GO_ANGLE`) is a specialized configuration for **ArduRover Sailboats**.

In sailing, a boat cannot sail directly into the wind. The "No-Go Zone" is the range of angles relative to the wind direction where the sails cannot generate lift and the boat will stall.

## Key Concepts

### 1. Tacking and Beating
When a target waypoint is directly upwind, the autopilot cannot sail a straight line to it. Instead, it must "Tack" (zig-zag) at an angle to the wind.
*   **`NO_GO_ANGLE`**: Defines the angle relative to the wind (e.g., 45 degrees) that the boat will maintain when trying to go upwind.
*   **Total Zone:** A `NO_GO_ANGLE` of 45 results in a 90-degree total arc centered on the wind direction where the boat will not enter.

## Parameter Breakdown

*   **`NO_GO_ANGLE`**: Upwind sailing limit (degrees).
    *   **Typical:** 40 to 50 degrees depending on the efficiency of the boat's keel and sail.

## Developer Notes
*   **Library:** `Rover/sailboat.cpp`.
*   **Logic:** Integrated with the L1 navigation controller to generate "Virtual Waypoints" that stay outside the no-go zone.