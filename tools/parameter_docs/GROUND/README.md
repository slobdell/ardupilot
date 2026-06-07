# Ground Steering Configuration (GROUND)

## Overview
The **GROUND** parameter group configures the **Ground Steering** logic for **ArduPlane**.

This system manages the transition from using the Rudder (airflow-based steering) to the Nose/Tail Wheel (mechanical ground-based steering) during takeoff and landing.

## Key Concepts

### 1. Ground Steering Alt (`GROUND_STEER_ALT`)
Defines the altitude (meters) above which ground steering is disabled.
*   **Takeoff:** Once the plane climbs above this height, the steering wheel is centered (or follows rudder) to reduce drag and prevent a sudden jerk if the wheels touch back down.

### 2. Steering Rate (`GROUND_STEER_DPS`)
Limits the maximum rotation rate (degrees per second) of the steering servo.
*   **Purpose:** Prevents high-speed "tank slappers" or tip-overs by preventing the pilot (or autopilot) from slamming the steering wheel to full lock at high taxi speeds.

## Parameter Breakdown

*   **`GROUND_STEER_ALT`**: Transition altitude (m).
*   **`GROUND_STEER_DPS`**: Max steering slew rate (deg/s).

## Integration Guide
*   **Nose Wheel:** Map your nose-wheel servo to `GroundSteering` (Function 39) rather than `Rudder` to utilize these specific ground-handling features.

## Developer Notes
*   **Library:** `ArduPlane/servos.cpp`.
*   **Context:** Only relevant for **ArduPlane**.