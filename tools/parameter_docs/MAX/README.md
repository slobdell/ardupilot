# Maximum Control Limits (MAX)

## Overview
The **MAX** parameter group (often appearing as `PSC_MAX_` in the full parameter list) defines the hard **Kinematic Limits** for the Position Controller.

These limits ensure that the autopilot never requests a velocity that exceeds the physical capabilities of the vehicle or the desires of the pilot for smoothness.

## Key Concepts

### 1. Velocity Limits (`MAX_VEL_...`)
*   **`MAX_VEL_XY`**: The maximum horizontal speed allowed in autonomous modes (Auto, Guided).
*   **`MAX_VEL_Z`**: The maximum climb and descent rate.

### 2. Position Error Limits (`MAX_POS_...`)
Defines the maximum allowed distance between the vehicle's actual position and its "Target" position before the controller stops trying to close the gap instantly (preventing violent corrections).

## Parameter Breakdown

*   **`MAX_VEL_XY`**: Horizontal velocity limit (m/s).
*   **`MAX_VEL_Z`**: Vertical velocity limit (m/s).

## Developer Notes
*   **Library:** `libraries/AC_PosControl`.
*   **Context:** These are the "Inner" limits of the navigation system. The higher-level mission speed (`WP_NAV_SPEED`) is usually capped by these.