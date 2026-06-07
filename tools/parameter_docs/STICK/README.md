# Stick Mixing Configuration (STICK)

## Overview
The **STICK** parameter group (specifically `STICK_MIXING`) configures the pilot's ability to "nudge" or override the autopilot's path while in **Autonomous** flight modes (Auto, Guided, RTL).

This is a critical safety feature that allows the pilot to steer around unexpected obstacles (like a person walking onto a landing pad) without needing to switch into a fully manual flight mode.

## Key Concepts

### 1. Manual Nudging
When stick mixing is enabled, moving the RC transmitter sticks adds an offset to the autopilot's target position or attitude.
*   **Action:** If the drone is flying a straight line in Auto and you push the roll stick right, the drone will bank right and move off the line. When you release the stick, it will steer back to the original mission path.

### 2. Mixing Modes (`STICK_MIXING`)
*   **0 (Disabled):** Sticks are completely ignored in Auto modes.
*   **1 (FBW):** Recommended. The sticks provide a stabilized override.
*   **3 (VTOL Yaw):** (QuadPlane) Allows the pilot to control heading during VTOL takeoff/landing while the autopilot handles position.

## Developer Notes
*   **Library:** `ArduPlane/Attitude.cpp`, `ArduCopter/control_auto.cpp`.
*   **Safety:** Ensures the pilot always has "ultimate authority" over the vehicle's trajectory.