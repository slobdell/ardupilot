# Gripper Configuration (GRIP)

## Overview
The **GRIP** parameter group configures the **Gripper / Cargo Release** subsystem. This allows the vehicle to carry, grab, and release payloads using various mechanisms (Servo, EPM, or DroneCAN).

## Key Concepts

### 1. Gripper Types (`GRIP_TYPE`)
Defines the hardware interface for the gripper.
*   **1 (Servo):** Standard PWM servo that moves between two positions.
*   **2 (EPM):** Electro-Permanent Magnet (e.g., OpenEPM). Uses a short pulse to magnetize/de-magnetize.
*   **3 (DroneCAN):** CAN-based gripper devices.

### 2. Grab and Release Positions
For servo-based grippers, defines the PWM endpoints.
*   **`GRIP_GRAB`**: PWM value to close the gripper.
*   **`GRIP_RELEASE`**: PWM value to open the gripper.
*   **`GRIP_NEUTRAL`**: PWM value for idle/disengaged state.

### 3. Automation (`GRIP_AUTOCLOSE`)
Can automatically close the gripper when a landing or proximity to a target is detected.

## Parameter Breakdown

*   **`GRIP_ENABLE`**: Master switch.
*   **`GRIP_TYPE`**: Hardware driver selection.
*   **`GRIP_CAN_ID`**: Node ID for DroneCAN grippers.

## Integration Guide
1.  **Pin:** Map a servo output to `Gripper` (Function 28).
2.  **Enable:** Set `GRIP_ENABLE = 1` and `GRIP_TYPE`.
3.  **Calibrate:** Set the `GRAB` and `RELEASE` PWM values so the mechanism operates without binding.
4.  **Control:** Map an RC channel to `Gripper` (RC Option 19) to control it manually.

## Developer Notes
*   **Library:** `libraries/AP_Gripper`.