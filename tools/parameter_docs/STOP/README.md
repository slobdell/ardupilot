# Stopping Distance Configuration (STOP)

## Overview
The **STOP** parameter group (specifically `STOP_DIST` or `DOCK_STOP_DIST`) configures the terminal phase of the **Autonomous Docking** maneuver for ArduRover.

## Key Concepts

### 1. Docking Termination
When a rover or boat is docking (e.g., for automated charging), it must stop precisely.
*   **`STOP_DIST`**: Defines the safety gap (in meters) between the autopilot's target location and the physical stopping point.
*   **Purpose:** Ensures the vehicle doesn't "over-ram" the dock, which could damage the charging pins or the airframe.

## Developer Notes
*   **Library:** `Rover/mode_dock.cpp`.
*   **Context:** Only relevant for **ArduRover**.