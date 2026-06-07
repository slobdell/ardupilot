# Moving Baseline Configuration (MB)

## Overview
The **MB** parameter group (specifically `MB_CAN_PORT`) configures the **GPS Moving Baseline** subsystem.

Moving Baseline is an advanced RTK technique where two GPS receivers on the same drone (a "Base" and a "Rover") calculate a precise relative position vector between each other. This vector provides an extremely accurate **Yaw (Heading)** source that is immune to magnetic interference.

## Key Concepts

### 1. Inter-Receiver Communication
The two GPS units must talk to each other to exchange raw measurement data.
*   **`MB_CAN_PORT`**: Selects the CAN bus port used for this inter-GPS communication if you are using DroneCAN GPS units (like the Here3+ or F9P CAN).

## Developer Notes
*   **Library:** `libraries/AP_GPS`.
*   **Requirement:** Requires two RTK-capable GPS receivers (e.g., u-Blox F9P).
*   **Benefit:** Allows flying in high-interference areas (near metal roofs, power lines) where a standard compass would fail.