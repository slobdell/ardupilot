# Architecture & Lessons Learned: Blimp/Tricopter VTOL

**Date:** December 30, 2025
**Scope:** Architecture, Codebase Refactor, and Hardware Integration findings.

## 1. Thrust Vectoring Controller (TVC) Logic

### 1.1 The "Two-Engine" Problem
Initially, the codebase contained two disparate control paths:
1.  **Standard Mixer (`AP_Motors6DOF`):** A linear mixer used by ArduSub/ArduPlane for simple 6DOF frames.
2.  **Custom TVC (`custom_main.cpp`):** A sophisticated "Brain" originally designed to run on a separate microcontroller, containing trigonometry (`atan2`), PIDs, and vector normalization logic.

**Resolution:**
We successfully integrated the "Brain" into the "Body". The `custom_main` logic was moved into the `AP_Motors` library and is now called directly by `AP_Motors6DOF::output_armed_stabilizing()`. This allows the blimp to use advanced vectoring math while remaining a standard ArduPilot vehicle type.

### 1.2 "Variable Hijacking"
To pass the calculated **Tilt Angle** from the TVC to the output mixer without breaking the `AP_Motors` abstraction layer:
*   We originally "hijacked" the `forward_thrust` variable.
*   **Refactor:** We replaced this with a dedicated `_tilt_angle` member variable. This ensures clear separation between **Thrust Magnitude** (Motors) and **Vector Angle** (Servo).

### 1.3 270-Degree Vectoring & Pitch Compensation
*   **The Physics:** `atan2(forward, vertical)` naturally handles a full 360° circle.
*   **The Problem:** Standard servos expect a 0-180° range.
*   **The Solution:**
    *   We defined physical limits: `MAX = 180°` (Down), `MIN = -90°` (Back).
    *   We use **Piecewise Normalization** to map the calculated angle (-135° to +180°) into a linear -1.0 to +1.0 control signal.
    *   **Pitch Compensation:** We add the AHRS pitch (`current_pitch_deg`) to the target angle *before* normalization. This ensures the thrust vector remains vertical relative to the ground, even if the blimp pitches up/down.

## 2. Hardware & Timer Conflicts (H743)

### 2.1 DShot vs. PWM Separation
ArduPilot determines output protocols per **Timer Group**.
*   **Conflict:** You cannot mix DShot and PWM on the same Timer.
*   **Discovery:**
    *   `MicoAir743` Group 1 (TIM1): Pins 1-4.
    *   `MicoAir743` Group 2 (TIM3): Pins 5-6.
*   **Solution:** We strictly mapped all DShot motors (Lift/Yaw) to Pins 1-4 and all PWM Servos to Pins 5-6.
*   **Critical Settings:** `SERVO_BLH_MASK = 15` (Enable DShot for 1-4 only) and `SERVO_BLH_AUTO = 0` (Disable auto-detection to prevent accidental DShot on servos).

### 2.2 The "Fake Prolific" Driver Saga
*   **Symptom:** Windows Code 10 error; Android QGC crash (`SIGSEGV`).
*   **Cause:** Counterfeit PL2303 chips in cheap USB-TTL adapters. Official drivers intentionally break them.
*   **Fix (Windows):** Rollback to 2008 driver (v3.3.2.105).
*   **Fix (Android):** Cannot change kernel driver. Use **Direct USB** (CDC-ACM) to the Flight Controller instead, or use a CP2102/FTDI adapter.

## 3. Flight Safety & Automation

### 3.1 Gravity-Assisted Descent
*   **Goal:** Prevent the autopilot from using "Active Downward Thrust" (Inverted Vectoring) during standard navigation, reserving it for pilot emergencies.
*   **Mechanism:** Gravity. The blimp has a natural terminal velocity (e.g., 2 m/s).
*   **Config:** Set `WPNAV_SPEED_DN` and `PILOT_SPEED_DN` to **1.0 m/s**.
*   **Result:** The Z-Controller sees the blimp falling "too fast" (due to gravity) and commands **Positive Lift** to brake. It never crosses zero into negative thrust, effectively locking out the hazardous vectoring regime during auto flight.

### 3.2 Bidirectional Throttle Input
*   **Challenge:** Standard ArduPlane throttle is 0-100%. We need -100% to +100%.
*   **Solution:** We implemented custom logic in `mode.cpp` to read the throttle stick as centered (1500 = 0).
*   **Safety:** We set `PILOT_THR_BHV = 1` to disable the "Low Throttle" arming check, ensuring the pilot can arm safely at neutral.

## 4. Build System (Waf)
*   **Discovery:** The `ardupilotwaf` tool does **not** recursively scan subdirectories in `libraries/`.
*   **Fix:** Source files (`.cpp`) must reside in the library root (e.g., `libraries/AP_Motors/`) to be compiled. Moving them to a `TVC/` subdirectory caused linking errors (`undefined reference`).

