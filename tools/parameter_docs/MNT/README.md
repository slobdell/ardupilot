# Mount / Gimbal Configuration (MNT)

## Overview
The **MNT** parameter group configures the **Camera Mount** (Gimbal) subsystem. ArduPilot supports up to 2 mounts (`MNT1` and `MNT2`).

The mount system allows the autopilot to stabilize the camera against the vehicle's movement and point the camera at specific targets (ROI).

## Key Concepts

### 1. Mount Types (`MNT_TYPE`)
Defines how the autopilot talks to the gimbal hardware.
*   **1 (Servo):** PWM servos for Tilt, Roll, and Yaw. Stabilization is done by the flight controller.
*   **3 (AlexMos):** Serial protocol for AlexMos/SimpleBGC gimbals.
*   **4 (STorM32):** Serial protocol for STorM32 gimbals.
*   **6 (DJI):** For DJI Zenmuse gimbals (via converter).
*   **8 (DroneCAN):** CAN-based gimbals (e.g., Gremsy CAN).

### 2. Stabilization
If using a simple Servo gimbal (`Type=1`), ArduPilot can use its IMU data to keep the camera level.
*   **`MNT_LEAD_PTCH` / `RLL`**: Predictive lag compensation.

### 3. Angles and Limits (`MNT_PITCH_MIN / MAX`)
Defines the mechanical range of motion of the gimbal.
*   **Pitch -90:** Camera pointing straight down.
*   **Pitch 0:** Camera pointing straight forward.

## Parameter Breakdown

*   **`MNT1_TYPE`**: Active driver.
*   **`MNT1_DEFLT_MODE`**: Behavior at boot (Retracted, Neutral, MAVLink, RC Target).
*   **`MNT1_RC_RATE`**: How fast the camera moves when you move the RC sticks (deg/s).

## Integration Guide
1.  **Hardware:** Mount the gimbal. If serial, connect to a Telem port.
2.  **Enable:** Set `MNT1_TYPE`.
3.  **Port:** (If serial) Set `SERIALx_PROTOCOL = 7` (AlexMos) or `8` (STorM32).
4.  **Verify:** Tilt the drone; the camera should remain level relative to the horizon.

## Developer Notes
*   **Library:** `libraries/AP_Mount`.
*   **Interaction:** Tightly integrated with the `CAM` group for automated photo triggering during survey missions.