# Level Flight Safety (LEVEL)

## Overview
The **LEVEL** parameter group (specifically `LEVEL_ROLL_LIMIT`) configures the maximum bank angle during critical flight phases for **ArduPlane**.

## Key Concepts

### 1. Ground Clearance
During Auto-Takeoff and the Flare portion of a landing, the plane is very close to the runway. Banking too steeply during these moments can cause a wingtip to strike the ground, resulting in a cartwheel crash.
*   **`LEVEL_ROLL_LIMIT`**: Limits the bank angle (degrees) when altitude is very low (< 5 meters).
    *   **Recommendation:** Keep small (e.g., 5-10 degrees).

## Developer Notes
*   **Library:** `ArduPlane/mode_landing.cpp`.
*   **Context:** Only relevant for fixed-wing aircraft.