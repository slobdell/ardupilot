# Forward Velocity Control (FW)

## Overview
The **FW** parameter group (specifically `FW_V_FF` and related gains) handles the **Forward Velocity** controller, primarily within the context of **Autonomous Autorotation** for helicopters.

## Key Concepts

### 1. Velocity FeedForward
In a descent (autorotation), the autopilot must maintain a specific forward ground/airspeed to preserve rotor RPM and reach the touchdown point.
*   **`FW_V_FF`**: Provides an immediate pitch command proportional to the target velocity, reducing the burden on the PID error-correction loops.

## Parameter Breakdown

*   **`FW_V_FF`**: Forward velocity feed-forward gain.

## Developer Notes
*   **Library:** `libraries/AC_Autorotation`.
*   **Relationship:** Complements the `AROT_` (Autorotation) and `AS_` (Acceleration) groups.