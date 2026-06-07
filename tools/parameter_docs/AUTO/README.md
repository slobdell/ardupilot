# Auto Mode Configuration (AUTO)

## Overview
The **AUTO** parameter group configures the behavior of the **Auto** flight mode, where the vehicle follows a pre-programmed mission (waypoints) uploaded from the Ground Control Station (GCS).

## Key Concepts

### 1. Mission Behavior (`AUTO_OPTIONS`)
A bitmask that modifies how the vehicle executes missions.
*   **Allow Arming:** Whether the vehicle can be armed directly into Auto mode.
*   **Takeoff behavior:** specific behaviors for VTOL takeoff.

### 2. Vehicle Specifics
*   **Rover:** `AUTO_KICKSTART` helps overcome static friction (stiction) by momentarily boosting throttle at the start of motion.
*   **Plane:** `AUTO_FBW_STEER` (sometimes aliased) might control steering assist.

## Parameter Breakdown

*   **`AUTO_OPTIONS`**: Bitmask of options.
*   **`AUTO_KICKSTART`**: (Rover) Throttle boost pulse duration/intensity.
*   **`AUTO_TRIGGER_PIN`**: Input pin to start the mission.

## Integration Guide
*   **Planning:** Use the "Plan" tab in Mission Planner or QGroundControl to create a mission.
*   **Upload:** "Write Waypoints" to the flight controller.
*   **Execution:** Switch to Auto mode. Ensure you have a GPS Lock (Green LED).

## Developer Notes
*   **Logic:** Handled by `ModeAuto` class in each vehicle directory (`ArduCopter/mode_auto.cpp`, `Rover/mode_auto.cpp`).