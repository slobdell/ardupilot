# Custom Rotation (CUST)

## Overview
The **CUST** parameter group allows for defining arbitrary 3D rotations (Euler Angles) for sensor mounting.

While standard ArduPilot parameters (like `AHRS_ORIENTATION` or `COMPASS_ORIENT`) provide a list of preset rotations (e.g., Yaw90, Pitch180), these presets are typically limited to 45-degree or 90-degree increments. The **CUST** group enables precise alignment for sensors mounted at odd angles (e.g., a GPS mast tilted 15 degrees back).

## Key Concepts

### 1. Enable Custom Rotation (`CUST_ROT_ENABLE`)
This master switch enables the custom rotation engine.

### 2. Defining the Rotation (`CUST_ROTx_...`)
You can define up to 2 unique custom rotations. Each is defined by a Roll, Pitch, and Yaw angle.
*   **Rotation 1:** Used when `AHRS_ORIENTATION` (or other orientation param) is set to **100 (Custom 1)**.
*   **Rotation 2:** Used when the parameter is set to **101 (Custom 2)**.

## Parameter Breakdown

*   **`CUST_ROT1_ROLL` / `PITCH` / `YAW`**: Euler angles for Custom Rotation 1.
*   **`CUST_ROT2_ROLL` / `PITCH` / `YAW`**: Euler angles for Custom Rotation 2.

## Integration Guide

### Example: Tilted GPS
If you mount your GPS/Compass module on a mast that is tilted 30 degrees backward:
1.  Set `CUST_ROT_ENABLE = 1`.
2.  Set `CUST_ROT1_PITCH = 30`.
3.  Set `CUST_ROT1_ROLL` and `CUST_ROT1_YAW` to 0 (assuming it faces forward).
4.  Set `COMPASS_ORIENT = 100` (Custom 1).
5.  Reboot and verify the heading works correctly when you tilt the vehicle.

## Developer Notes
*   **Library:** `libraries/AP_CustomRotations`
*   **Math:** Uses standard Euler sequence (Yaw -> Pitch -> Roll) to construct a rotation matrix.