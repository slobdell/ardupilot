# Mission Sequencing Configuration (MIS)

## Overview
The **MIS** parameter group configures how the autopilot executes and manages **Waypoints** and **Missions**.

This group controls the high-level logic of the Auto flight mode.

## Key Concepts

### 1. Mission Completion (`MIS_DONE_BEHAVE`)
Defines what the vehicle does after the last waypoint in the mission is reached.
*   **0:** Stay in Auto (Loiter at last WP).
*   **1:** Switch to RTL (Return to Launch).
*   **2:** (Rover) Switch to Hold.

### 2. Restart Logic (`MIS_RESTART`)
Determines if a mission resumes from the last waypoint or starts from the beginning if the mode is toggled.
*   **0 (Resume):** If you switch from Auto to Loiter and back to Auto, the vehicle continues where it left off.
*   **1 (Restart):** Every time you enter Auto mode, the mission starts from Waypoint 1.

## Parameter Breakdown

*   **`MIS_TOTAL`**: Read-only count of mission items.
*   **`MIS_OPTIONS`**: Bitmask for specialized behaviors (e.g., skip first waypoint).

## Integration Guide
*   **Safe Ops:** Set `MIS_DONE_BEHAVE = 1` (RTL) for long-range missions to ensure the drone comes home once its work is done.

## Developer Notes
*   **Library:** `libraries/AP_Mission`.