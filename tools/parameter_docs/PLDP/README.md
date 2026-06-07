# Payload Place Configuration (PLDP)

## Overview
The **PLDP** parameter group configures the **Autonomous Payload Placement** (Payload Place) feature. This mode allows the drone to descend over a target, detect when the payload has touched the ground (e.g., via slack in the winch or a weight-off-hook sensor), and autonomously release it.

## Key Concepts

### 1. Touchdown Detection (`PLDP_THRESH`)
The system monitors the motor thrust required to hover. When the payload touches the ground, the drone becomes "lighter," and the required thrust drops.
*   **`PLDP_THRESH`**: The percentage drop in thrust required to trigger the "Touchdown" state.

### 2. Descent Speed (`PLDP_SPEED_DN`)
Defines the slow, controlled speed used for the final drop-off.

## Parameter Breakdown

*   **`PLDP_THRESH`**: Thrust change threshold.
*   **`PLDP_DELAY`**: Time to wait after touchdown before releasing the gripper.
*   **`PLDP_RNG_MAX`**: Maximum altitude allowed to start the placement procedure.

## Developer Notes
*   **Library:** `libraries/AC_PayloadPlace`.
*   **Mission Item:** Triggered by the `NAV_PAYLOAD_PLACE` waypoint.