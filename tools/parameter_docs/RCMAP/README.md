# RC Channel Mapping (RCMAP)

## Overview
The **RCMAP** parameter group defines the default mapping of the four primary control axes (Roll, Pitch, Yaw, Throttle) to RC input channels.

By default, ArduPilot follows the **AETR** (Aileron, Elevator, Throttle, Rudder) or **TAER** standards. However, if your transmitter uses a different channel order, you can use these parameters to remap the logic without changing physical wires.

## Key Concepts

### 1. Axis Mapping
*   **`RCMAP_ROLL`**: Maps the Roll (Aileron) function to a channel (1-16).
*   **`RCMAP_PITCH`**: Maps the Pitch (Elevator) function to a channel.
*   **`RCMAP_THROTTLE`**: Maps the Throttle function to a channel.
*   **`RCMAP_YAW`**: Maps the Yaw (Rudder) function to a channel.

## Developer Notes
*   **Library:** `libraries/AP_RCProtocol`.
*   **Standard Defaults:**
    *   Channel 1: Roll
    *   Channel 2: Pitch
    *   Channel 3: Throttle
    *   Channel 4: Yaw