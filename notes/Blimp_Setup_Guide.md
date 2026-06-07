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
Ensure `libraries/AP_CustomConfig/AP_CustomConfig.h` contains the following **Critical Configuration**:

```cpp
// Backend Selection
#define ENABLE_TRICOPTER_VTOL_BACKEND 1
#define TRICOPTER_IS_BLIMP true

// Safety & Control Logic
#define EMERGENCY_BLIMP_MANUAL_MODE true      // Enables Channel 9 Override
#define DISABLE_POSITION_HEADING_LOITER false // Disable Weathervaning to maintain position heading
#define CUSTOM_WEATHERVANE false              // Use standard Loiter logic (with heading enabled)
#define FAILSAFE_KILL_MOTORS true             // Immediately disarm on Radio Failsafe

// Physical Airframe Constraints (Must match your servo geometry)
#define FORWARD_FLIGHT_PHYSICAL_ANGLE_DEG 180.0f // Angle of motors at max forward tilt (Relative to fuselage)
#define REVERSE_FLIGHT_PHYSICAL_ANGLE_DEG -90.0f // Angle of motors at max reverse tilt (Relative to fuselage)
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

### 3.0. Standard Serial Port Map (MatekH743)

| Port | Protocol | Device | Baud | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **SERIAL1** | **9** (Lidar) | **Rangefinder** | **115200** | Benewake TF02-Pro |
| **SERIAL4** | **32** (MSP) | **Optical Flow** | **115200** | Matek 3901-L0X |

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

*Because the blimp tilts both forward (positive) and backward (negative), TRIM must be set to the **physical midpoint** of the servo's total travel — i.e. the servo's mechanical center. If TRIM is off-center, the positive and negative tilt ranges will be unequal and hover will not be at true vertical.*

### 4.3. Yaw Control
*   **Dual Actuation:** Yaw commands drive both the **Tail Motor (4)** and the **Rudder Servo (6)** simultaneously.
*   **Reversible:** The tail motor spins in reverse for one direction and forward for the other.

### 4.4. Automated Flight & Safety (Z-Controller)
While the pilot has full access to -1.0 to +1.0 thrust (including emergency downward vectoring), the autopilot and Loiter modes should generally only use gravity for descent.
*   **Descent Priority:** To ensure the system never "needs" to use active downward thrust automatically, you must limit the commanded descent velocity to be less than the blimp's natural unpowered terminal velocity.
*   **Vertical Speed Requirements:**
    *   `Q_WP_SPD_DN` (Auto Mode Descent): Set to **30** (30 cm/s).
    *   `Q_WP_SPD_UP` (Auto Mode Climb): Set to **30** (30 cm/s).
    *   `Q_PILOT_SPD_DN` (Loiter Mode Descent): Set to **0** (Matches Up Speed).
    *   `Q_PILOT_SPD_UP` (Loiter Mode Climb): Set to **30** (30 cm/s).
    *   `Q_PILOT_ACCEL_Z`: Set to **50** (50 cm/s²). Smooth response (0.6s to full speed).
*   **Behavior:** These conservative speeds (0.3 m/s) ensure the blimp remains stable and within its thrust authority during altitude changes.

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

### 5.1a. Weathervaning (QLOITER)
The blimp is designed to hover nose-into-wind for efficient loiter. This is handled by ArduPlane's stock `AC_WeatherVane` library — no custom code required. It activates automatically in QLOITER when the pilot releases the yaw stick, and deactivates the moment the pilot applies yaw input.

*   `WVANE_DIRECTION`: **1** (Nose into wind)
*   `WVANE_GAIN`: **1.0** (Start here; increase for more aggressive response)
*   `WVANE_ANG_MIN`: **1.0** (Deadzone in degrees; prevents hunting when nearly aligned)

**Note (ArduCopter builds):** When testing with the copter binary, weathervaning in LOITER requires `custom_weathervane = true` in `libraries/AP_CustomConfig/AP_CustomConfig.cpp`. The stock WVANE parameters alone are not sufficient in the copter build — they only take effect through the custom `auto_yaw.get_heading()` path. See `ArduCopter/mode_loiter.cpp`.

### 5.2. Flight Modes
This aircraft operates exclusively in VTOL (Quad) modes.
*   **Mode Channel:** Set `FLTMODE_CH` = **6**.
*   **Mode 1:** `QSTABILIZE` (Manual Control)
*   **Mode 2:** `QLOITER` (Position Hold - requires Optical Flow)
*   **Mode 3:** `QHOVER` (Altitude Hold with manual vectoring)

### 5.3. Motor & Servo Functions (MicoAir743 Specific)

| Pin | Function | Param value | Mixer output |
|-----|----------|-------------|--------------|
| 1 | Motor 1 (Right Lift) | `SERVO1_FUNCTION = 33` | — |
| 3 | Motor 2 (Left Lift) | `SERVO3_FUNCTION = 35` | — |
| 4 | Motor 3 (Tail Yaw) | `SERVO4_FUNCTION = 34` | — |
| 5 | Scripting2 — Tilt servo | `SERVO5_FUNCTION = 95` | `tilt_angle` |
| 6 | Scripting3 — Rudder servo | `SERVO6_FUNCTION = 96` | `rudder_out` |
| 7 | Scripting4 — Elevator servo | `SERVO7_FUNCTION = 97` | `elevator_out` |
| 8 | Scripting5 — Aileron left | `SERVO8_FUNCTION = 98` | `aileron_out` |
| 9 | Scripting6 — Aileron right | `SERVO9_FUNCTION = 99` | `-aileron_out` |

**All surface outputs use Scripting channels.** ArduPlane's own mixing pipeline writes to named channels (`k_aileron`, `k_elevator`, `k_rudder`) in QSTABILIZE and would overwrite a custom mixer using those functions. Scripting channels are never touched by ArduPlane's mixer. See `libraries/AP_Motors/AP_Motors6DOF.cpp` for the routing logic.

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
    *   `Q_A_RAT_YAW_FF`: **0.5** (Primary control authority - Direct Stick-to-Motor). Verified effective value.
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

### 5.7. Airspeed Configuration (CRITICAL)
For Blimp operation, especially in zero-airspeed hover or VTOL modes, you **MUST** allow the airspeed constraints to go to zero.
*   **`AIRSPEED_MIN`**: Set to **0**.
    *   *Why?* ArduPlane defaults this to 5 m/s or similar. If left at default, the TECS controller (speed/height) will think the aircraft is under-speeding when hovering and may apply aggressive pitch-down or throttle logic to "recover" airspeed, causing instability. Setting it to 0 tells the controller that hovering (0 m/s) is a valid flight state. This requires the custom firmware build where `MIN_AIRSPEED_MIN` constraint is removed.

*   **`ARSPD_USE` / `ARSPD_TYPE`**:
    *   **If you do NOT have a physical airspeed sensor connected:** Set `ARSPD_USE = 0` and `ARSPD_TYPE = 0`.
    *   *Crucial:* If you enable the sensor but do not connect it, the EKF (AHRS) will report "Unhealthy" in Plane modes (MANUAL, STABILIZE) because it expects data that isn't arriving. You will be unable to arm in these modes.

### 5.8. Loiter & Navigation Tuning (Blimp Inertia)
Blimps have high inertia and low thrust authority. Default QuadPlane settings are too aggressive.
*   `Q_LOIT_SPEED`: **200** (2 m/s). Limits max speed in Loiter to prevent overshooting.
*   `Q_LOIT_ACC_MAX`: **50** (50 cm/s²). Limits acceleration demand.
*   `Q_LOIT_BRK_ACCEL`: **25** (25 cm/s²). Gentle braking to prevent violent pitch oscillations when stopping.
*   `Q_LOIT_BRK_JERK`: **100**. Smooths the onset of braking.
*   `Q_LOIT_ANG_MAX`: **20** (Degrees). Limits the maximum tilt/vectoring angle commanded by the position controller.
*   `WP_RADIUS`: **10** (Meters). For Plane modes.
*   `Q_WP_RADIUS`: **10** (Meters). For VTOL/Loiter modes.
    *   *Note:* A large radius is critical to prevent the blimp from oscillating around waypoints it cannot physically turn sharp enough to hit.

### 5.9. Failsafe Configuration
*   **RC Failsafe:** What happens if the radio link drops?
    *   **Behavior:** The blimp is configured with `FAILSAFE_KILL_MOTORS = true`. On any radio failsafe (short or long), the aircraft will **immediately disarm**, killing all motors and servos. This allows the blimp to drift safely using its natural buoyancy.
    *   `THR_FAILSAFE`: Ensure your receiver is set up to trigger this. For ELRS, it usually holds "No Pulses" or a specific preset. ArduPilot detects "No Pulses" easily.
    *   **Action:** Set `FS_THR_ENABLE = 1` and `FS_THR_VALUE` appropriately.
*   **EKF Failsafe:** What happens if the Optical Flow or MAVLink GPS glitches?
    *   `FS_EKF_ACTION`: **1** (QLand). Safe slow descent.
    *   `FS_EKF_THRESH`: **0.8**.
*   **Battery Failsafe:**
    *   `BATT_FS_LOW_ACT`: **2** (QLand).

## 5.10. Platform Stabilization (New Feature)
The firmware supports active stabilization for a 2-axis gimbal or payload platform, keeping it level relative to the horizon regardless of the blimp's pitch/roll.

*   **Concept:** The system outputs an inverted attitude signal to counteract the airframe's movement.
*   **Logic:** `Output = -Attitude`.
*   **Scaling:** The default scaling is **±45° = ±100% servo travel**.
    *   Example: If the blimp pitches up +45°, the servo is commanded to -100% (to tilt the platform down 45°).
*   **Configuration:**
    *   **Platform Roll Servo:** Set `SERVOn_FUNCTION` = **98** (Scripting 5).
    *   **Platform Pitch Servo:** Set `SERVOn_FUNCTION` = **99** (Scripting 6).
*   **Enablement:** This feature is enabled via the `optical_flow_stabilized_roll` and `optical_flow_stabilized_pitch` flags in `libraries/AP_CustomConfig/AP_CustomConfig.h`.

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

5.  **Transition Ground Test:**
    *   Arm in `QSTABILIZE`. Switch to `FBWA`.
    *   Verify: Motors stay spinning. Pitch stick tilts motors. Yaw stick moves rudder servo.
    *   Switch back to `QSTABILIZE`.

## 7. Recommended Peripherals

### 7.1. Rangefinder
*   **Model:** **Benewake TF02-Pro** (Lidar).
*   **Range:** ~40m (Indoor/Outdoor).
*   **Connection:** Serial (UART1).
*   **Parameters:**
    *   `SERIAL1_PROTOCOL`: **9** (Rangefinder).
    *   `SERIAL1_BAUD`: **115** (115200).
    *   `RNGFND1_TYPE`: **27** (Benewake-TF03/TF02-Pro).
    *   `RNGFND1_MIN_CM`: **1**.
    *   `RNGFND1_MAX_CM`: **4000**.
    *   `RNGFND1_ORIENT`: **25** (Down).

### 7.2. Optical Flow
*   **Model:** **Matek 3901-L0X** (MSP).
*   **Connection:** Serial (UART4).
*   **Parameters:**
    *   `SERIAL4_PROTOCOL`: **32** (MSP).
    *   `SERIAL4_BAUD`: **115** (115200).
    *   `FLOW_TYPE`: **6** (MSP).
    *   `FLOW_ADDR`: **0**.

## 8. EKF3 Configuration (Indoor GPS + Optical Flow)

This configuration fuses **MAVLink GPS** (Android Location Services) for absolute position with **Optical Flow** for precision velocity/loiter, and **Lidar** for altitude.

*   **Enable EKF3:** `EK3_ENABLE = 1`
*   **Optical Flow Mode:**
    *   `EK3_FLOW_USE`: **1** (Navigation).
    *   *Note:* The default for QuadPlane is 2 (Terrain). You **MUST** change this to 1 to use Optical Flow for position/velocity control.

*   **Source 1 (Primary - GPS):**
    *   `EK3_SRC1_POSXY`: **3** (GPS) - Uses MAVLink GPS for absolute position.
    *   `EK3_SRC1_VELXY`: **3** (GPS) - Uses MAVLink GPS for velocity.
    *   `EK3_SRC1_POSZ`: **2** (RangeFinder) - Uses Lidar for altitude.
    *   `EK3_SRC1_VELZ`: **0** (None).
    *   `EK3_SRC1_YAW`: **1** (Compass).

*   **Source 2 (Secondary - OptFlow):**
    *   `EK3_SRC2_POSXY`: **0** (None).
    *   `EK3_SRC2_VELXY`: **5** (Optical Flow).
    *   `EK3_SRC2_POSZ`: **0** (None).
    *   `EK3_SRC2_VELZ`: **0** (None).
    *   `EK3_SRC2_YAW`: **0** (None).

*   **Fusion Settings:**
    *   `EK3_SRC_OPTIONS`: **1** (FuseAllVelocities). This fuses *both* GPS and Optical Flow velocities for optimal stability.

*   **GPS Configuration (for MAVLink GPS):**
    *   `GPS_TYPE`: **1** (Auto) or **14** (MAV).

*   **Optical Flow Settings:**
    *   `FLOW_TYPE`: **[Your Sensor Type]** (e.g., 6 for MSP, 5 for CXOF).
    *   `FLOW_POS_X`, `FLOW_POS_Y`, `FLOW_POS_Z`: Measure sensor offset from CG in meters.

*   **Lidar Settings (Critical for Flow):**
    *   `EK3_RNG_USE_HGT`: **70** (%) - Use Lidar for altitude when below 70% of max range.
    *   `EK3_RNG_USE_SPD`: **2.0** (m/s) - Max speed to use Lidar.

---
**Note:** This configuration uses `OPEN_LOOP_SERVO_MODE` logic, bypassing internal angular PIDs for the tilt mechanism and relying on direct trigonometric mapping for robust, predictable vectoring.