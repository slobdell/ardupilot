# AutoTune Configuration (AUTOTUNE)

## Overview
The **AUTOTUNE** parameter group configures the **AutoTune** flight mode. This is an automated system-identification routine where the autopilot rapidly twitches the vehicle in Roll, Pitch, and Yaw to measure its physical response (inertia, authority, damping) and automatically calculates the optimal PID gains (`ATC_` group).

## Key Concepts

### 1. Aggressiveness (`AUTOTUNE_AGGR`)
This parameter controls how "sharp" or "locked-in" the resulting tune will be.
*   **0.1 (Default):** Standard crisp tune. Good for most racers and camera drones.
*   **0.075:** Softer tune. Better for large cinematic builds, older frames, or if the default tune causes oscillation.
*   **0.05:** Very soft/damped.

### 2. Axes Selection (`AUTOTUNE_AXES`)
Selects which axes to tune during the session.
*   **1:** Roll only.
*   **2:** Pitch only.
*   **4:** Yaw only.
*   **7 (Default):** Roll, Pitch, and Yaw.

## Parameter Breakdown

*   **`AUTOTUNE_AGGR`**: Aggressiveness target.
*   **`AUTOTUNE_AXES`**: Bitmask of axes to tune.
*   **`AUTOTUNE_MIN_D`**: Minimum D-gain to ensure damping.

## Integration Guide

### Running AutoTune
1.  **Setup:** Map a switch to AutoTune mode (or use `AUTOTUNE_AXES`).
2.  **Safety:** Find a large open area on a calm day.
3.  **Process:**
    *   Take off and establish a stable hover (AltHold or Loiter).
    *   Switch to AutoTune.
    *   The vehicle will start twitching (Roll -> Pitch -> Yaw).
    *   **Pilot Input:** If the vehicle drifts too far, use the sticks to gently bring it back. The tuning pauses while sticks are moved and resumes when centered.
4.  **Completion:** The twitching stops. Land and Disarm to save the new PIDs. Switch out of AutoTune *before* disarming to discard them.

## Developer Notes
*   **Library:** `ArduCopter/mode_autotune.cpp`
*   **Algorithm:** Iterative Step Response optimization. It tries to match the requested Rate vs Actual Rate with minimal overshoot.