# Docking Mode (DOCK)

## Overview
The **DOCK** parameter group configures the **Autonomous Docking** behavior for **ArduRover**. This mode allows a rover to precisely approach and connect with a docking station (usually for charging).

## Key Concepts

### 1. Approach Logic
The rover approaches a target (the dock) at a slow speed.
*   **Direction:** The rover expects to approach from a specific vector.
*   **Correction:** It uses heading correction to ensure it enters straight.

## Parameter Breakdown

*   **`DOCK_SPEED`**: Approach speed (m/s). Needs to be slow enough to stop accurately but fast enough to maintain steering.
*   **`DOCK_DIR`**: The direction (heading) the dock faces.
*   **`DOCK_STOP_DIST`**: Distance from the target to cut motors.

## Integration Guide
*   **Target:** The dock location is usually provided by a mission waypoint or a localized beacon.
*   **Usage:** Switch to `DOCK` mode when near the station.

## Developer Notes
*   **Library:** `Rover/mode_dock.cpp`.