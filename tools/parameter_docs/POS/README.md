# Position Controller Configuration (POS)

## Overview
The **POS** parameter group (often appearing as `PSC_POSXY_P` or `PSC_POSZ_P`) configures the **Position Loop Gains**.

## Key Concepts

### 1. Position Error to Velocity
The position controller is the outer-most loop in the navigation hierarchy. It compares the vehicle's actual position (GPS/EKF) against the target position (Waypoint).
*   **`POS_P`**: The Proportional gain. It defines the "Stiffness" of the position hold.
    *   **Higher values:** The drone will react more aggressively to stay exactly on the point.
    *   **Lower values:** The drone will drift more but movements will be smoother.

## Developer Notes
*   **Library:** `libraries/AC_PosControl`.
*   **Hierarchy:** `Pos_Error * POS_P` -> `Target_Velocity`.