# Comprehensive Blimp Setup Guide

**Date:** December 30, 2025
**Target Airframe:** Indoor Blimp (Inherent Roll Stability, 2x Vectoring Gondola Motors, 1x Bidirectional Yaw Motor, 1x Rudder Servo)
**Firmware Base:** ArduPlane (QuadPlane)

## 1. Executive Summary

This document outlines the configuration for a custom Blimp airframe. The system uses a modified `AP_Motors6DOF` backend (`ENABLE_TRICOPTER_VTOL_BACKEND` + `TRICOPTER_IS_BLIMP`) to provide advanced thrust vectoring control.

**Key Concept:**
The Blimp is treated as a **QuadPlane** (VTOL Plane) with a custom mixer.
- **Lift/Pitch:** Controlled by the two Gondola Motors (via differential and collective throttle) and inherent buoyancy.
- **Thrust Vectoring:** Forward/Backward motion is achieved by tilting the Gondola Motors.
    - **Logic:** A custom trigonometric solver calculates the optimal Tilt Angle and Throttle Boost based on pilot inputs.
    - **Compensation:** The Tilt Angle is automatically offset by the airframe's current Pitch to maintain a consistent thrust vector relative to the ground.
- **Yaw:** Controlled by a Bidirectional Tail Motor and a Rudder Servo (coupled).

## 2. Firmware Build Instructions

You must build a custom firmware binary with the specific backend flags enabled.

### 2.1. Prerequisites
Ensure you have the ArduPilot build environment set up (waf, gcc-arm-none-eabi, etc.).

### 2.2. Configuration
**Step 1: Verify Feature Flags**
Ensure `ArduCopter/custom_config.h` (or your board's header) contains:
```cpp
#define ENABLE_TRICOPTER_VTOL_BACKEND 1
#define TRICOPTER_IS_BLIMP true
```

**Step 2: Configure Waf**
Run the configure command. Replace `--board MicoAir743` with your specific board target.
```bash
./waf configure --board MatekH743 --enable-scripting --disable-crsf
```
*Note: `--enable-scripting` is required for the backend logic.*

**Step 3: Build ArduPlane**
Build the plane binary.
```bash
./waf plane
```

**Step 4: Upload**
Upload the resulting `arduplane.apj` to your flight controller.

## 3. Hardware & Wiring Guide

The backend uses a specific hardcoded mixer. Wire your ESCs and Servos exactly as follows.

### 3.1. Mixer Map (Conceptual vs. Physical)

| Output | Blimp Function | Protocol | Description |
| :--- | :--- | :--- | :--- |
| **1** | **Right Lift** | DShot | Main Lift. (Non-Reversible) |
| **2** | **Left Lift** | DShot | Main Lift. (Non-Reversible) |
| **3** | **Tail Yaw** | **Bi-Dir DShot** | Yaw Control. Spins reverse for left yaw, forward for right yaw. |
| **4** | **Rudder Servo** | PWM | Duplicate Yaw Control. Linked to tail motor logic. |
| **5** | **Tilt Servos** | PWM | Controls vectoring angle. **Trim=Vertical**. |
| **6** | **Debug Thrust** | DShot | **Debug Only.** Direct mapping of Forward Stick for bench testing. |

### 3.2. Detailed Wiring

1.  **Lift ESCs (1 & 2):** Connect to FC Outputs 1 & 2. Standard DShot.
2.  **Yaw ESC (3):** Connect to FC Output 3. **Bidirectional (3D) Mode.**
3.  **Rudder Servo (4):** Connect to FC Output 4.
4.  **Tilt Servos (5):** Connect to FC Output 5.
5.  **Debug ESC (6):** Connect to FC Output 6.

## 4. Theory of Operation & Control Logic

The system uses a "TVC" (Thrust Vectoring Controller) logic block integrated into the motor mixer.

### 4.1. Forward / Vectoring Logic (The Core)
*   **Trigonometry:** The controller calculates the target servo angle using `atan2(forward_cmd, vertical_cmd)`.
*   **Thrust Compensation:** As the motors tilt forward, the throttle is automatically boosted (up to ~2x) to maintain the vertical lift component.
*   **Pitch Compensation:** If the blimp pitches up (e.g. +20°), the servos automatically tilt forward an extra 20° to keep the thrust vector vertical relative to the ground.
*   **Limits:**
    *   **Command Limit:** ±60° (Safety limit for throttle boost).
    *   **Physical Limit:** +89° / -10° (Hard mechanical limits).

### 4.2. Servo Configuration (CRITICAL)
You must configure the `SERVO5` parameters to define the physical range of your tilt mechanism. The code uses **TRIM** as the vertical reference.

*   **Vertical (Hover):** Set `SERVO5_TRIM` to the PWM value where motors point **Straight Up** (90° to fuselage).
*   **Forward (Cruise):** Set `SERVO5_MAX` to the PWM value where motors point **Forward** (0° to fuselage).
*   **Backward (Reverse):** Set `SERVO5_MIN` to the PWM value where motors point **Backward** (approx -10°).

*The code interpolates from Trim->Max for forward commands, and Trim->Min for reverse commands. This ensures accurate vertical hover even if the mechanism is asymmetric.*

### 4.3. Yaw Control
*   **Dual Actuation:** Yaw commands drive both the **Tail Motor (4)** and the **Rudder Servo (6)** simultaneously.
*   **Reversible:** The tail motor spins in reverse for one direction and forward for the other.

### 4.4. Attitude Stabilization Logic
*   **Roll & Pitch:** Active stabilization for Roll and Pitch is **DISABLED** in the mixer (factors set to 0.0).
    *   **Why?** Blimps are "pendulum stable" (Center of Gravity is significantly below Center of Buoyancy). They naturally return to level.
    *   **The Problem with PIDs:** Attempting to actively stabilize pitch with small propellers often leads to "hunting" or oscillation because the motors lack the authority to quickly overcome the massive rotational inertia and aerodynamic damping of the hull.
    *   **Result:** The motors only respond to **Throttle** (Altitude), **Yaw** (Heading), and **Vectoring** (Position). The airframe handles stability naturally.

## 5. Parameter Configuration

Set these parameters in Mission Planner/QGC.

### 5.1. Class & Type
*   `Q_FRAME_CLASS`: **1** (Quad)
*   `Q_FRAME_TYPE`: **1** (X)
*   `Q_ENABLE`: **1** (Enable QuadPlane)

### 5.2. Motor & Servo Functions
*   `SERVO1_FUNCTION`: **33** (Motor 1) -> Right Lift
*   `SERVO2_FUNCTION`: **34** (Motor 2) -> Left Lift
*   `SERVO4_FUNCTION`: **36** (Motor 4) -> Yaw Motor
*   `SERVO5_FUNCTION`: **37** (Motor 5) -> Tilt Servo
*   `SERVO6_FUNCTION`: **38** (Motor 6) -> Rudder Servo
*   `SERVO7_FUNCTION`: **39** (Motor 7) -> Debug Forward

### 5.3. ESC & DShot
*   `MOT_PWM_TYPE`: **6** (DShot600) or **4** (DShot150).
*   `SERVO_BLH_AUTO`: **1** (Enable BLHeli passthrough).
*   `SERVO_BLH_MASK`: **11** (Enable for Chan 1, 2, 4). *Do not enable for Servos (5,6).*
*   `SERVO_BLH_BDMASK`: **8** (Enable Bidirectional DShot for Chan 4 ONLY).

### 5.4. PID Tuning (Blimp Specifics)
*   `Q_A_RAT_RLL_P`, `Q_A_RAT_PIT_P`, `Q_A_RAT_YAW_P`: **0.05** (Start very low).
*   `Q_A_RAT_RLL_I`, `Q_A_RAT_PIT_I`, `Q_A_RAT_YAW_I`: **0.05**.
*   `Q_A_RAT_RLL_D`, `Q_A_RAT_PIT_D`, `Q_A_RAT_YAW_D`: **0**.
*   `Q_M_THST_HOVER`: **0.3** (Adjust for buoyancy).

## 6. Pre-Flight Verification

1.  **Servo Setup:**
    *   Set `SERVO5_FUNCTION = 0` (Disabled).
    *   Use the "Servo/Relay" tab in Mission Planner to find the exact PWM values for Vertical, Forward, and Backward.
    *   Enter these into `SERVO5_TRIM`, `SERVO5_MAX`, `SERVO5_MIN`.
    *   Restore `SERVO5_FUNCTION = 37`.

2.  **Motor Direction:**
    *   Use Motor Test. Ensure 1 & 2 blow **Down**.
    *   Ensure 4 (Tail) can spin both ways.

3.  **Vectoring Test (QSTABILIZE):**
    *   Arm. Raise throttle slightly.
    *   Pitch Stick Forward -> Servos should tilt **Forward**.
    *   Pitch Stick Back -> Servos should tilt **Back**.
    *   **Compensation Test:** Pitch the nose UP manually. Servos should tilt **Forward** to compensate (staying vertical to ground).

4.  **Debug Test:**
    *   If enabled, Motor 7 should spin proportional to your forward pitch stick input.

---
**Note:** This configuration uses `OPEN_LOOP_SERVO_MODE` logic, bypassing internal angular PIDs for the tilt mechanism and relying on direct trigonometric mapping for robust, predictable vectoring.