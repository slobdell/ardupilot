# Deceleration Limits (DECEL)

## Overview
The **DECEL** parameter group (specifically `DECEL_MAX`) sets the physical braking limits for **ArduRover** (Ground Vehicles and Boats).

Unlike aircraft, ground vehicles need separate limits for acceleration (to prevent wheelies) and deceleration (to prevent skidding or front-flips).

## Key Concepts

### 1. Braking Aggression
This parameter tells the navigation controller how hard it can apply the brakes when approaching a waypoint or stopping.
*   **Too High:** The vehicle might skid, lock wheels, or tip forward.
*   **Too Low:** The vehicle will overshoot waypoints or crash into obstacles because it can't stop in time.

## Parameter Breakdown

*   **`DECEL_MAX`**: Maximum deceleration in m/s/s.
    *   **Example:** 1.0 m/s/s means the vehicle can slow down by 1 m/s every second.

## Integration Guide
1.  **Test:** Drive at full speed in Manual mode and slam the brakes.
2.  **Observe:** Does it skid? Does the nose dip dangerously?
3.  **Tune:** Set `DECEL_MAX` slightly lower than the physical limit you observed.

## Developer Notes
*   **Library:** `ArduRover/AP_L1_Control` (Navigation).