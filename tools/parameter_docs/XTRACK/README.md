# Crosstrack Configuration (XTRACK)

## Overview
The **XTRACK** parameter group defines the limits for **Crosstrack Error** management. "Crosstrack" is the perpendicular distance from the vehicle to the planned mission line.

## Key Concepts

### 1. Error Limits (`XTRACK_MAX`)
Defines the maximum allowed distance (meters) the vehicle can deviate from the path before the autopilot considers the mission "Invalid" or takes emergency action (e.g., stopping or circling).

### 2. Correction Angle (`XTRACK_ANG_LIM`)
(Sub/Plane) Limits the angle at which the vehicle is allowed to turn *towards* the path to correct an error.
*   **Purpose:** Prevents the vehicle from turning 90 degrees to the path, which could cause a stall or unstable behavior.

## Developer Notes
*   **Library:** `libraries/AP_L1_Control`.