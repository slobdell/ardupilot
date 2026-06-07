# Acrobatic Mode Configuration (ACRO)

## Overview
The **ACRO** parameter group governs the behavior of the **Acro** flight mode (also known as Rate Mode). In this mode, the pilot directly controls the **angular velocity** (rotation rate) of the vehicle. When the sticks are centered, the vehicle holds its current attitude (angle), not level.

*   **For Copters:** This is the primary mode for FPV racing, freestyle, and precise cinematic movements. It feels "locked in" and requires constant pilot input to hover.
*   **For Planes:** This mode acts like a "Fly-By-Wire Rate" mode. The control surfaces move to produce a commanded rotation rate. If you let go of the stick, the plane stops rotating and holds that bank/pitch angle (stabilized), counteracting turbulence.

## Key Concepts

### 1. Rate Command (`ACRO_RP_RATE` / `ACRO_ROLL_RATE`)
This defines the responsiveness of the vehicle.
*   **Definition:** The maximum rotation rate (in degrees per second) achieved at full stick deflection.
*   **Impact:** Higher values make the vehicle snap and roll faster (snappier). Lower values make it smoother and more docile (cinematic).
*   **Copter:** `ACRO_RP_RATE` controls both Roll and Pitch rates. `ACRO_Y_RATE` controls Yaw.
*   **Plane:** `ACRO_ROLL_RATE` and `ACRO_PITCH_RATE` are often independent.

### 2. Expo (`ACRO_EXPO`)
Exponential (Expo) softens the stick response around the center without reducing the maximum rate at the endpoints.
*   **Positive Expo:** Makes fine adjustments near the center stick easier while still allowing fast flips at full stick.
*   **Linear (0):** Direct mapping of stick position to rate command.

### 3. Acro Trainer (`ACRO_TRAINER`)
A safety feature for learning Acro.
*   **Function:** It prevents the pilot from flipping the vehicle completely over. If the vehicle reaches a certain bank angle limit (e.g., 45 degrees), the autopilot overrides the rate command to stop further rotation.
*   **Levels:**
    *   0: Disabled (Full freedom).
    *   1: Leveling (Automatically returns to level when sticks are released).
    *   2: Limited (Stops at angle limits, holds attitude when released).

### 4. Heading Lock (`ACRO_LOCKING`)
Determines whether the autopilot aggressively fights to hold a specific heading/attitude when the sticks are centered.
*   **Locked:** The integrator builds up to correct any uncommanded drift (wind, CG shift).
*   **Unlocked/Drift:** The vehicle acts more like a raw mechanical machine, allowing slight drift which can feel more "natural" for airplanes in smooth turns.

## Parameter Breakdown

### Copter Specific
*   **`ACRO_RP_RATE`**: Maximum Roll/Pitch rate (e.g., 360 deg/s).
*   **`ACRO_Y_RATE`**: Maximum Yaw rate.
*   **`ACRO_RP_EXPO`**: Exponential curve for Roll/Pitch.
*   **`ACRO_THR_MID`**: Throttle stick position that corresponds to "Hover Throttle" (only used for Expo calculation on throttle).

### Plane Specific
*   **`ACRO_ROLL_RATE`**: Maximum Roll rate (deg/s).
*   **`ACRO_PITCH_RATE`**: Maximum Pitch rate (deg/s).
*   **`ACRO_LOCKING`**: Enable/Disable strict attitude locking (1=Locked, 0=Rate Only).

## Integration Guide

### Tuning for FPV Racing (Copter)
1.  **Set Rates:** Start with `ACRO_RP_RATE` at 360 deg/s. Pros often use 600-900 deg/s.
2.  **Add Expo:** Increase `ACRO_RP_EXPO` (e.g., 0.1 to 0.3) to regain precision for small movements.
3.  **Disable Trainer:** Ensure `ACRO_TRAINER` is 0 for full flips and rolls.

### Tuning for Smooth Flight (Plane)
1.  **Check Mechanical Limits:** Ensure `ACRO_ROLL_RATE` is achievable by your airframe. Commanding 360 deg/s on a slow trainer will just saturate the servos (integral windup).
2.  **Locking:** Use `ACRO_LOCKING = 1` for a "fly on rails" feel. Use `0` if you want the nose to drop naturally in turns.

## Developer Notes
*   **Code Locations:**
    *   **Copter:** `ArduCopter/mode_acro.cpp` - Implements the `ModeAcro` class.
    *   **Plane:** `ArduPlane/mode_acro.cpp` - Implements the fixed-wing rate controller logic.
*   **Logic:** The pilot input is converted to a `target_rate` vector. This is fed into the PID controller (`ATC_RAT_RLL`, etc.) which compares `target_rate` vs `gyro_rate` to drive the motors/servos.