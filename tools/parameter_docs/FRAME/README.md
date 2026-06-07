# Frame Configuration (FRAME)

## Overview
The **FRAME** parameter group defines the physical structure and motor layout of the vehicle. This is one of the first and most critical steps in configuring a new drone.

The frame settings tell the autopilot:
1.  **Class:** What *type* of vehicle is it? (Quad, Hexa, Octa, Heli, etc.)
2.  **Type:** How are the motors *arranged*? (X, Plus, V, H, etc.)
3.  **Config:** (Sub) Specific motor mixer matrices for underwater vehicles.

## Key Concepts

### 1. Frame Class (`FRAME_CLASS`)
Sets the number of motors and general physics model.
*   **1:** Quad.
*   **2:** Hexa.
*   **3:** Octa.
*   **...**

### 2. Frame Type (`FRAME_TYPE`)
Sets the rotation of the motor arms.
*   **1:** X-Frame (Standard).
*   **0:** Plus-Frame (Motors on the nose/tail/sides).

### 3. Sub Frame Config (`FRAME_CONFIG`)
(Specific to ArduSub) Selects from predefined thruster layouts like "Vectored" or "Vectored-6DOF."

## Parameter Breakdown

*   **`FRAME_CLASS`**: Vehicle architecture.
*   **`FRAME_TYPE`**: Geometric layout.
*   **`FRAME_CONFIG`**: (Sub only) Thruster mixer.

## Integration Guide
*   **Setup:** Use the "Frame Setup" screen in your GCS. Changing these values usually requires a reboot to load the new mixer matrix.
*   **Warning:** If you have an X-frame but set it to Plus-frame, the drone will flip immediately on takeoff.

## Developer Notes
*   **Library:** `libraries/AP_Motors`.
*   **Mixers:** Each class/type combination loads a specific static matrix that defines how Roll/Pitch/Yaw/Throttle maps to each motor PWM.