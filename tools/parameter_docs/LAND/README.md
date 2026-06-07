# Landing Configuration (LAND)

## Overview
The **LAND** parameter group configures the final stages of flight: **Landing** and **Auto-Landing**.

Effective landing parameters ensure the vehicle touches down softly, stays straight on the runway, and disarms promptly after contact.

## Key Concepts

### 1. Vertical Speed (Copter)
*   **`LAND_SPEED`**: The slow descent rate (m/s) used during the final few meters of touchdown.
*   **`LAND_SPEED_HIGH`**: The faster descent rate used for the initial descent from altitude before slowing down for the final touchdown.

### 2. Plane Auto-Landing
*   **`LAND_FLARE_ALT`**: The altitude (meters) at which the plane begins to "Flare" (pitch up to stall onto the runway).
*   **`LAND_PITCH_DEG`**: The target pitch angle during the flare.
*   **`LAND_ABORT_DEG`**: If the pilot (or autopilot) decides to abort the landing, this is the pitch angle it will climb at.

### 3. Deep Stall Landing (`LAND_DS_...`)
(Advanced Plane feature) Used for landing in very tight spaces by intentionally stalling the wing at a high angle of attack.

## Parameter Breakdown

*   **`LAND_TYPE`**: Selection of landing logic (e.g., standard vs deepstall).
*   **`LAND_DISARMDELAY`**: How long to wait after touchdown before automatically disarming.
*   **`LAND_OPTIONS`**: Bitmask for specific behaviors (e.g., allow repositioning with sticks during auto-land).

## Integration Guide
*   **Soft Landing:** If your copter bounces on landing, reduce `LAND_SPEED`.
*   **Landing Flare:** If your plane hits the runway nose-first, increase `LAND_FLARE_ALT` or `LAND_PITCH_DEG`.

## Developer Notes
*   **Library:** `libraries/AP_Landing` (Shared), `ArduCopter/mode_land.cpp`, `ArduPlane/mode_landing.cpp`.