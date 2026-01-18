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

### 3.1. Mixer Map (MicoAir743 Specific)

| Output | Blimp Function | Protocol | Timer Group | Description |
| :--- | :--- | :--- | :--- | :--- |
| **1** | **Right Lift** | DShot | TIM1 | Main Lift. (Motor 1) |
| **2** | **Left Lift** | DShot | TIM1 | Main Lift. (Motor 2) |
| **3** | **Tail Yaw** | **Bi-Dir DShot** | TIM1 | Yaw Control. Reversible. (Motor 3) |
| **4** | **(Optional)** | - | - | Unused. |
| **5** | **Rudder Servo** | PWM | TIM3 | Yaw Duplicate. (**Scripting 3**) |
| **6** | **Tilt Servos** | PWM | TIM3 | Vectoring. (**Scripting 2**) |

### 3.2. Detailed Wiring (MicoAir743)

1.  **Lift ESCs (1 & 2):** Connect to Pins 1 & 2.
2.  **Yaw ESC (3):** Connect to Pin 3. **MUST be configured for Bidirectional (3D) Mode.**
3.  **Debug ESC (4):** Connect to Pin 4 (Optional).
4.  **Rudder Servo (5):** Connect to Pin 5.
5.  **Tilt Servos (6):** Connect to Pin 6.

*Note: DShot and PWM are separated into Timer Groups TIM1 and TIM3 to prevent protocol conflicts.*

## 4. Theory of Operation & Control Logic

The system uses a "TVC" (Thrust Vectoring Controller) logic block integrated into the motor mixer.

### 4.1. Forward / Vectoring Logic (The Core)
*   **Trigonometry:** The controller calculates the target servo angle using `atan2(forward_cmd, vertical_cmd)`.
*   **Thrust Compensation:** As the motors tilt forward, the throttle is automatically boosted (up to ~2x) to maintain the vertical lift component.
*   **Pitch Compensation:** If the blimp pitches up (e.g. +20°), the servos automatically tilt forward an extra 20° to keep the thrust vector vertical relative to the ground.
*   **Limits:**
    *   **Command Limit:** ±60° (Safety limit for throttle boost).
    *   **Physical Limit:** +89° / -10° (Hard mechanical limits).

### 4.2. Advanced Vectoring: 270° Range & Emergency Descent
While the standard configuration assumes a range for Forward/Backward flight, the blimp supports an extended **270° Servo Range** (e.g., -90° Back to +180° Down).
*   **Concept:** Instead of reversing motors to generate downward thrust (inefficient), the system can rotate the motors 180° forward to point **Straight Down**.
*   **Benefit:** This allows the propellers to spin in their efficient direction, generating 100% thrust for emergency descent (e.g., fighting strong thermal updrafts).
*   **Implementation:** This requires configuring the `SERVOn_MAX` PWM to correspond to the 180° (Down) position. The control logic remains the same; the trigonometry naturally handles the extended range.

### 4.3. Servo Configuration (CRITICAL)
You must configure the `SERVO5` parameters to define the physical range of your tilt mechanism. The code uses **TRIM** as the vertical reference.

*   **Vertical (Hover):** Set `SERVO5_TRIM` to the PWM value where motors point **Straight Up** (90° to fuselage).
*   **Forward (Cruise):** Set `SERVO5_MAX` to the PWM value where motors point **Forward** (0° to fuselage).
*   **Backward (Reverse):** Set `SERVO5_MIN` to the PWM value where motors point **Backward** (approx -10°).

*The code interpolates from Trim->Max for forward commands, and Trim->Min for reverse commands. This ensures accurate vertical hover even if the mechanism is asymmetric.*

### 4.3. Yaw Control
*   **Dual Actuation:** Yaw commands drive both the **Tail Motor (4)** and the **Rudder Servo (6)** simultaneously.
*   **Reversible:** The tail motor spins in reverse for one direction and forward for the other.

### 4.4. Automated Flight & Safety (Z-Controller)
While the pilot has full access to -1.0 to +1.0 thrust (including emergency downward vectoring), the autopilot and Loiter modes should generally only use gravity for descent.
*   **Descent Priority:** To ensure the system never "needs" to use active downward thrust automatically, you must limit the commanded descent velocity to be less than the blimp's natural unpowered terminal velocity.
*   **Vertical Speed Requirements:**
    *   `WPNAV_SPEED_DN` (Auto Mode Descent): Set to **100 cm/s**.
    *   `PILOT_SPEED_DN` (Loiter Mode Descent): Set to **100 cm/s**.
    *   `PILOT_SPEED_UP` (Loiter Mode Climb): Set to **200 cm/s**.
    *   `PILOT_ACCEL_Z`: Set to **50 cm/s²**.
    *   `WPNAV_ACCEL_Z`: Set to **50 cm/s²**.
*   **Behavior:** As long as gravity accelerates the blimp faster than the `DN_SPEED` limit, the autopilot will keep the motors in the "Positive Lift" regime to govern the descent, never crossing the 0.0 threshold into "Active Down" vectoring.

### 4.5. Dual-Mode Architecture (Unified Mixing)
The firmware automatically switches between two distinct control models based on the flight mode (`in_vtol_mode`).

*   **Copter Mode (QSTABILIZE / QHOVER):**
    *   Uses **TVC (Thrust Vectoring Controller)** logic.
    *   Sticks control absolute physical vectors (Vertical, Forward, Lateral).
    *   Supports automatic pitch compensation to maintain vertical thrust.
*   **Plane Mode (STABILIZE / MANUAL):**
    *   Uses **Direct Actuator Mapping**.
    *   The backend becomes a "dumb" actuator for the ArduPlane mixer.
    *   Active stabilization (Roll/Pitch PIDs) is **disabled** to prevent motor/servo hunting, relying on the blimp's natural buoyancy stability.

### 4.6. Plane Mode Pitch Logic (Split Control)
The firmware implements a **Split Control** architecture for pitch, blending the Tail Elevator and Thrust Vectoring based on stick input magnitude (`BLIMP_ELEVATOR_SPLIT`).

*   **Configuration:** Currently set to **0.0** (Immediate Vectoring).
*   **Behavior (Split = 0.0):**
    *   **Elevator:** Instantly saturates to full deflection with any pitch input.
    *   **Vectoring:** Begins tilting immediately from the Forward (90°) cruise position.
*   **Mapping (Asymmetric 270°):**
    *   **Stick Center (Neutral):** Motors point **90° Forward**.
    *   **Stick Full Back (Pitch Up):** Motors point **0° Up** (or back to -90°).
    *   **Stick Full Forward (Pitch Down):** Motors point **180° Down**.

*Note:* This architecture allows future airframes with effective tail surfaces to use the elevator for small corrections (Split > 0) before engaging the vectoring mechanism.

**Note on Manual Mode:** The firmware includes a specific override to keep motors active and controllable even in `MANUAL` mode, bypassing the standard QuadPlane safety shutdown for blimp operation.

## 5. Parameter Configuration

Set these parameters in Mission Planner/QGC.

### 5.1. Class & Type
*   `Q_ENABLE`: **1** (Enable QuadPlane)
*   `Q_FRAME_CLASS`: **1** (Quad)
*   `Q_FRAME_TYPE`: **1** (X)

### 5.2. Flight Modes
This aircraft operates exclusively in VTOL (Quad) modes.
*   **Mode Channel:** Set `FLTMODE_CH` = **6**.
*   **Mode 1:** `QSTABILIZE` (Manual Control)
*   **Mode 2:** `QLOITER` (Position Hold - requires Optical Flow)
*   **Mode 3:** `QHOVER` (Altitude Hold with manual vectoring)

### 5.3. Motor & Servo Functions (MicoAir743 Specific)
*   **Physical Pins (Hardware Control):**
    *   `SERVO1_FUNCTION`: **33** (Motor 1) -> Right Lift
    *   `SERVO3_FUNCTION`: **34** (Motor 2) -> Left Lift
    *   `SERVO4_FUNCTION`: **35** (Motor 3) -> Tail Yaw Motor
    *   `SERVO5_FUNCTION`: **96** (Scripting 3) -> Rudder Servo
    *   `SERVO6_FUNCTION`: **95** (Scripting 2) -> Tilt Servo
    *   `SERVO7_FUNCTION`: **97** (Scripting 4) -> Elevator Servo (Optional)
*   **Critical Plane Logic (Dummy Captures):**
    You **MUST** assign these functions to unused channels (e.g. 13, 14, 15) to enable the Plane mixer logic, even if nothing is physically connected.
    *   `SERVO13_FUNCTION`: **21** (Rudder)
    *   `SERVO14_FUNCTION`: **19** (Elevator)
    *   `SERVO15_FUNCTION`: **70** (Throttle)

### 5.4. ESC & DShot (MicoAir743)
*   **`MOT_PWM_TYPE`**: **5** (DShot300).
*   **`SERVO_BLH_AUTO`**: **0** (Disabled - rely on manual mask for hybrid PWM/DShot).
*   **`SERVO_BLH_MASK`**: **15** (Enables DShot for pins 1, 2, 3, 4).
*   **`SERVO_BLH_3DMASK`**: **4** (or **8** depending on mapping).
    *   *Critical:* This mask must include the channel for the **Tail Motor (3D)**. It tells ArduPilot to use 3D DShot command encoding (where 1500 PWM = Stop). Without this, the 3D ESC will not arm or spin correctly on DShot.
*   **`SERVO_BLH_OTYPE`**: **5** (Explicitly set to DShot300 for AM32/BLHeli).
*   **`SERVO_BLH_BDMASK`**: **0** (Disable Bidirectional DShot unless RPM filtering is needed).

### 5.5. PID Tuning (Blimp Specifics)
*   **Pitch & Roll:**
    *   `Q_A_RAT_RLL_P`, `Q_A_RAT_PIT_P`: **0.05** (Start very low).
    *   `Q_A_RAT_RLL_I`, `Q_A_RAT_PIT_I`: **0.05**.
    *   `Q_A_RAT_RLL_D`, `Q_A_RAT_PIT_D`: **0**.
*   **Yaw (Crucial for Inertia):**
    *   `Q_A_RAT_YAW_P`: **0.1** (Low P to prevent wag).
    *   `Q_A_RAT_YAW_I`: **0.01** (Minimal I to prevent windup).
    *   `Q_A_RAT_YAW_D`: **0.0** (Disabled).
    *   `Q_A_RAT_YAW_FF`: **0.5** (Primary control authority - Direct Stick-to-Motor).
    *   `Q_A_RATE_Y_MAX`: **30** (Limit max yaw rate to 30 deg/s to prevent saturation).
*   **Thrust:**
    *   `Q_M_THST_HOVER`: **0.3** (Adjust for buoyancy).

### 5.6. Arming & Safety Configuration (CRITICAL)
Since the throttle stick controls negative thrust (down) when pulled back, you cannot use standard "Low Throttle" arming.
*   **Throttle Behavior:** Set `PILOT_THR_BHV` = **1** (Center Stick = Idle).
    *   *Function:* This disables the "Low Throttle" arming check and tells the motor spool logic that "Center" is the idle position when landed. It does *not* automatically remap the flight control stick, which is handled by the custom firmware logic.
*   **Arming Switch:** Set `RC9_OPTION` to **153** (Arm/Disarm).
    *   *Procedure:* Center Throttle Stick -> Flip Switch to Arm.
*   **Rudder Arming:** Set `ARMING_RUDDER` = **0** (Disabled) to prevent accidental stick arming.
*   **Arming Checks (CRITICAL):**
    *   Set `ARMING_CHECK` to a value that excludes the **RC** check (or set to **0** for testing).
    *   *Why?* The standard ArduPilot RC check requires the throttle to be at minimum PWM to arm. In this blimp configuration, minimum PWM is **Full Reverse**, while the expected idle position is **Neutral (1500)**. Keeping the RC check enabled will prevent arming at the neutral position.
*   **Pre-Arm Bypass:**
    *   Set `Q_ASSIST_SPEED` = **-1** (strictly required to disable the check).

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

## 7. Recommended Peripherals

### 7.1. Rangefinder
*   **Model:** **Benewake TF02-Pro** (Lidar).
*   **Range:** ~40m (Indoor/Outdoor).
*   **Connection:** Serial (UART).
*   **Parameters:**
    *   `SERIALx_PROTOCOL`: **9** (Rangefinder).
    *   `SERIALx_BAUD`: **115** (115200).
    *   `RNGFND1_TYPE`: **19** (Benewake TF02).
    *   `RNGFND1_MIN_CM`: **10**.
    *   `RNGFND1_MAX_CM`: **4000**.
    *   `RNGFND1_ORIENT`: **25** (Down).

---
**Note:** This configuration uses `OPEN_LOOP_SERVO_MODE` logic, bypassing internal angular PIDs for the tilt mechanism and relying on direct trigonometric mapping for robust, predictable vectoring.