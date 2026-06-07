# Attitude Control (ATC)

## Overview
The **ATC** parameter group contains the core **PID (Proportional-Integral-Derivative)** tuning parameters for **ArduCopter** and **QuadPlane** (in VTOL modes).

This library is the "muscle" of the flight controller. It is responsible for taking the pilot's desire (e.g., "Lean 30 degrees right") and converting it into precise motor commands to achieve and maintain that attitude against wind and disturbances.

## Key Concepts: The Control Loop

The attitude control logic works in a cascaded (nested) structure:

### 1. Angle Controller (Outer Loop)
*   **Input:** Desired Angle (from Pilot stick or Navigation).
*   **Action:** Calculates how fast the vehicle needs to rotate to reach that angle.
*   **Output:** Target Rate (deg/s).
*   **Parameters:** `ATC_ANG_RLL_P`, `ATC_ANG_PIT_P`, `ATC_ANG_YAW_P`.
*   **Logic:** `Target_Rate = Error_Angle * P_Gain`.

### 2. Rate Controller (Inner Loop)
*   **Input:** Target Rate (from Angle Controller) vs. Actual Rate (from Gyro).
*   **Action:** Calculates the necessary motor power adjustments.
*   **Output:** Motor Mixer Command (-1 to +1).
*   **Parameters:** `ATC_RAT_RLL_P/I/D/FF`.
*   **Logic:**
    *   **FF (FeedForward):** Immediate output proportional to the target. Primary driver for sharp handling.
    *   **P (Proportional):** Immediate correction based on error.
    *   **I (Integral):** Long-term correction for imbalances/wind.
    *   **D (Derivative):** Dampening to prevent overshoot.

### 3. Acceleration Limits
*   `ATC_ACCEL_R_MAX` / `P_MAX` / `Y_MAX`: Limits how quickly the Angle Controller can request a change in rate. This limits the "jerkiness" or physical aggression of the drone.

## Parameter Breakdown

### Rate Loops (The most critical tuning)
*   **`ATC_RAT_RLL_P`, `I`, `D`, `FF`**: Roll axis tuning.
*   **`ATC_RAT_PIT_P`, `I`, `D`, `FF`**: Pitch axis tuning.
*   **`ATC_RAT_YAW_P`, `I`, `D`, `FF`**: Yaw axis tuning.

### Angle Loops (Feel & Stability)
*   **`ATC_ANG_RLL_P`**: Roll angle stiffness (typically 4.5 - 10.0).
*   **`ATC_ANG_PIT_P`**: Pitch angle stiffness.

### Filters
*   **`ATC_RAT_RLL_FLTT`**: Target filter frequency (smooths inputs).
*   **`ATC_RAT_RLL_FLTE`**: Error filter frequency (smooths D-term noise).

## Integration Guide

### Basic Tuning Workflow
1.  **AutoTune:** The best way to tune `ATC` parameters is to use the **AutoTune** flight mode. It automatically tests the vehicle's response and calculates optimal P, I, D, and Angle P values.
2.  **Manual Adjustment:**
    *   **Oscillation (Fast Wobble):** Reduce P and D terms.
    *   **Sluggishness:** Increase P and FF.
    *   **Drift/Angle Hold Failure:** Increase I.
    *   **Overshoot (Bounce back):** Increase D or Reduce P.

## Developer Notes
*   **Library:** `libraries/AC_AttitudeControl`
*   **Vehicle:** **ArduCopter**, **ArduPlane** (QuadPlane), **ArduSub**.
*   **Evolution:** Modern ArduPilot relies heavily on **FeedForward (FF)** for responsiveness, whereas older versions relied more on P.