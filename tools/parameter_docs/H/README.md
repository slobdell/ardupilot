# Traditional Helicopter Configuration (H)

## Overview
The **H** parameter group (often appearing as `H_` or `HELI_`) is the comprehensive configuration set for **Traditional Helicopters** (Single Main Rotor + Tail Rotor, or Tandem).

ArduPilot's helicopter support is world-class, handling complex swashplate mixing, governor control, and autorotation.

## Key Concepts

### 1. Swashplate Mixing (`H_SW_...`)
Defines the mechanical arrangement of the servos driving the main rotor.
*   **`H_SW_TYPE`**: Supports H3, H1, H4, and others.
*   **`H_SW_COL_DIR`**: Reverses the collective pitch direction.

### 2. Rotor Speed Control (RSC)
Manages the motor/engine power to maintain a constant rotor RPM.
*   **`H_RSC_MODE`**: 1 (Interlocked PWM), 2 (Set-point), 3 (Throttle Curve), or 4 (Governor).
*   **`H_RSC_SETPOINT`**: The target rotor speed.

### 3. Tail Rotor Configuration (`H_TAIL_...`)
*   **`H_TAIL_TYPE`**: 0 (Servo), 1 (Servo with yaw-to-collective mix), 2 (Direct Drive Fixed Pitch - DDFP).
*   **`H_COL2YAW`**: Collective-to-Yaw compensation (pre-compensates for torque changes).

### 4. Collective Limits (`H_COL_...`)
*   **`H_COL_MIN` / `MAX`**: The allowable range of collective pitch (e.g., -3 degrees to +12 degrees).

## Parameter Breakdown

*   **`H_RSC_MODE`**: The "throttle" logic for the main rotor.
*   **`H_COL_HOVER`**: The collective pitch required for a stable hover (learned or manual).
*   **`H_FLYBAR_MODE`**: Enables logic for legacy mechanical flybar heads (0 for Flybarless).

## Integration Guide
*   **Safety:** **Always use a Motor Interlock switch.** Helicopters are physically dangerous; the Interlock ensures the rotor only spins when commanded.
*   **Servo Check:** Use the `H_SV_TEST` feature to verify swashplate movement before mounting blades.

## Developer Notes
*   **Library:** `libraries/AP_Motors/AP_MotorsHeli_Single.cpp`, `AP_MotorsHeli_Tandem.cpp`.
*   **Complexity:** Helicopter tuning is significantly more complex than Multicopter tuning and relies heavily on accurate collective/yaw pre-compensation.