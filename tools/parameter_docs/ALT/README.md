# Altitude Configuration (ALT)

## Overview
The **ALT** parameter group contains miscellaneous altitude-related settings.

**Note:** This group is a bit of a "catch-all" in some documentation sets.
*   **`ALT_OFFSET`** is a core **ArduPlane** parameter for adjusting the mission altitude frame.
*   **`ALT_MIN`** is typically associated with the **Proximity** library (`PRX_ALT_MIN`), defining the floor for obstacle avoidance.

## Key Concepts

### 1. Altitude Offset (`ALT_OFFSET`)
(ArduPlane Only)
This parameter shifts the autopilot's internal reference for "Home Altitude" without actually moving the Home point.
*   **Usage:** Useful for landing at a location that is at a different physical elevation than the takeoff point, or for adjusting altitude during repeated auto-landings in a circuit.
*   **Math:** `Target_Alt = Mission_Alt + ALT_OFFSET`.

### 2. Proximity Floor (`ALT_MIN`)
(From `AP_Proximity`)
Defines the minimum altitude (AGL) required for the obstacle avoidance system to engage.
*   **Purpose:** Prevents the ground itself from being detected as an "obstacle" during takeoff and landing, which could cause the vehicle to panic or refuse to land.

## Parameter Breakdown

*   **`ALT_OFFSET`**: Altitude offset in meters. Positive adds height to targets.
*   **`ALT_MIN`**: Minimum altitude for proximity sensors to be active.

## Developer Notes
*   **Context:** `ALT_OFFSET` is defined in `ArduPlane/Parameters.cpp`. `ALT_MIN` is defined in `libraries/AP_Proximity`.