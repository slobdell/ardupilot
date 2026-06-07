# Circle Mode Configuration (CIRCLE)

## Overview
The **CIRCLE** parameter group configures the behavior of the **Circle** flight mode. In this mode, the vehicle flies a perfect circle around a center point (typically the location where the mode was engaged) while keeping the nose pointed towards the center (ROI).

## Key Concepts

### 1. Radius and Direction
*   **`CIRCLE_RADIUS`**: Defines the size of the circle (in centimeters or meters depending on firmware version, typically cm).
*   **`CIRCLE_RATE`**: Defines the angular speed of the orbit (deg/s).
*   **`CIRCLE_DIR`**: 0 = Clockwise, 1 = Counter-Clockwise. *(Note: Often controlled by the sign of `CIRCLE_RATE` in newer versions).*

### 2. Point of Interest
By default, the vehicle faces the center.
*   **`CIRCLE_OPTIONS`**: Can be used to change facing behavior (e.g., face direction of flight).

## Parameter Breakdown

*   **`CIRCLE_RADIUS`**: Radius of the orbit.
*   **`CIRCLE_RATE`**: Angular velocity (deg/s). High rate + small radius = fast flight.

## Integration Guide
*   **Engagement:** Fly to the desired center point, switch to `CIRCLE`. The vehicle will fly out to `CIRCLE_RADIUS` and begin orbiting.
*   **Adjustment:** In Copter, you can often adjust the radius dynamically using the Pitch/Roll stick while in Circle mode.

## Developer Notes
*   **Library:** `ArduCopter/mode_circle.cpp`, `ArduPlane/mode_circle.cpp`.
*   **Difference:** Plane often uses `LOITER_RADIUS` for standard loiters, but `CIRCLE` mode is specific.