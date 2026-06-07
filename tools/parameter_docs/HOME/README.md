# Home Point Configuration (HOME)

## Overview
The **HOME** parameter group (specifically `HOME_RESET_ALT`) configures how the autopilot handles the reference altitude for the **Home Position**.

The Home point is the location where the vehicle armed (or where GPS lock was first obtained). It is the target for the Return to Launch (RTL) mode.

## Key Concepts

### 1. Altitude Resets
On startup, the autopilot sets the current altitude to 0. However, if the barometer drifts significantly while waiting for GPS lock, the "Home" altitude might be offset.
*   **`HOME_RESET_ALT`**: (ArduPlane) Defines the altitude change (threshold) required to trigger an automatic reset of the 0m reference before takeoff.

## Parameter Breakdown

*   **`HOME_RESET_ALT`**: Reset threshold in meters.

## Developer Notes
*   **Library:** `libraries/AP_AHRS`.
*   **Safety:** Accurate home altitude is critical for ensuring the vehicle clears obstacles during the return flight and lands at the correct height.