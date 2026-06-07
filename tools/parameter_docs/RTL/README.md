# Return to Launch Configuration (RTL)

## Overview
The **RTL** parameter group configures the **Return to Launch** (RTL) flight mode. This is the primary safety mode for ArduPilot vehicles, providing an autonomous way for the vehicle to return to its starting point and land.

RTL is often triggered automatically by Failsafes (Radio, Battery, GCS) or manually by the pilot.

## Key Concepts

### 1. Return Altitude (`RTL_ALT`)
Defines the altitude the vehicle will climb (or descend) to before starting its trip back to Home.
*   **Safety:** This must be high enough to clear any trees, buildings, or hills between the drone and Home.

### 2. Final Phase (`RTL_ALT_FINAL`)
Determines what the drone does once it arrives back over Home.
*   **0:** Land immediately.
*   **>0:** Loiter at this altitude (meters) until the pilot takes over or the battery fails.

### 3. Climb Behavior (`RTL_CLIMB_MIN`)
Ensures that if the vehicle is already above `RTL_ALT`, it doesn't dive until it gets home. It also ensures a minimum climb if already low.

## Parameter Breakdown

*   **`RTL_ALT`**: Return altitude (centimeters or meters, check units).
*   **`RTL_SPEED`**: Speed (m/s) during the return trip.
*   **`RTL_AUTOLAND`**: (Plane) Automatically starts a landing sequence upon arrival.

## Integration Guide
*   **Setup:** Always set `RTL_ALT` to at least 20 meters higher than the tallest obstacle in your flying area.
*   **Verify:** Perform a manual RTL test early in your flight to ensure the vehicle behaves as expected.

## Developer Notes
*   **Library:** `ArduCopter/mode_rtl.cpp`, `ArduPlane/mode_rtl.cpp`.
*   **Navigation:** Uses the standard position/velocity controllers to execute the path home.