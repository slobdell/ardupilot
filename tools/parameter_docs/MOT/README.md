# Motor Configuration & Thrust Logic (MOT)

## Overview
The **MOT** parameter group is the core configuration for the **Motor Mixer** and **Thrust Linearization** system in multicopters, helicopters, and blimps.

This library translates the high-level PID demands (Roll, Pitch, Yaw, Throttle) into specific electrical signals sent to the ESCs. It also handles "Voltage Compensation," ensuring the drone feels the same at the end of a battery pack as it does at the start.

## Key Concepts

### 1. PWM & Signal Type (`MOT_PWM_TYPE`)
Defines the communication protocol with the ESCs.
*   **0:** Normal PWM (50-490Hz).
*   **4:** DShot150.
*   **6:** DShot600.

### 2. Spin Levels (`MOT_SPIN_ARM` / `MIN` / `MAX`)
*   **`SPIN_ARM`**: The speed motors spin when armed but throttle is zero.
*   **`SPIN_MIN`**: The lowest speed allowed in flight (ensures motors don't stall during aggressive descents).
*   **`SPIN_MAX`**: Usually 0.95 (95%) to leave headroom for attitude control at full throttle.

### 3. Thrust Linearization (`MOT_THST_EXPO`)
Brushless motors do not produce linear thrust (50% PWM is not 50% thrust).
*   **`THST_EXPO`**: A curve factor (0 to 1) that "flattens" the thrust response so the PID controllers have consistent authority across the entire throttle range.

### 4. Voltage Compensation (`MOT_BAT_VOLT_...`)
As battery voltage drops, the same PWM signal produces less thrust. The autopilot automatically increases the signal to compensate.
*   **`MOT_BAT_VOLT_MAX`**: Voltage of a full pack.
*   **`MOT_BAT_VOLT_MIN`**: Voltage of an empty pack.

## Parameter Breakdown

*   **`MOT_THST_HOVER`**: The learned or manual throttle value (0.0 - 1.0) required to maintain hover.
*   **`MOT_SLEWRATE`**: Limits how fast the throttle can increase (prevents current spikes).
*   **`MOT_YAW_HEADROOM`**: Reserves a portion of motor power for yaw control even at full throttle.

## Integration Guide
1.  **ESC Calibration:** Not needed for DShot. For PWM, must match `MOT_PWM_MIN` and `MAX`.
2.  **Hover Tune:** Hover the vehicle in a stable mode (AltHold/Loiter). Check `MOT_THST_HOVER` in the logs and set it manually if `MOT_HOVER_LEARN` is disabled.
3.  **Vibration:** If the vehicle is "jumpy," check if `MOT_THST_EXPO` is too high for your motor/prop combo.

## Developer Notes
*   **Library:** `libraries/AP_Motors`.
*   **Hierarchy:** `AP_MotorsMatrix` (Multicopter), `AP_MotorsHeli` (Helicopter).