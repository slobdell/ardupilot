# PosHold Mode Configuration (PHLD)

## Overview
The **PHLD** parameter group configures the **PosHold** flight mode. PosHold is a hybrid mode for multicopters that combines the stick-feel of "AltHold" with the automated position-holding of "Loiter."

## Key Concepts

### 1. Hybrid Control
*   **Active Sticks:** The drone feels like it is in a stabilized/manual mode. When you push the stick, it banks and moves directly proportional to your input.
*   **Released Sticks:** When you center the sticks, the autopilot automatically applies a brake maneuver and then "locks" the current position using GPS.

### 2. Braking (`PHLD_BRAKE_...`)
Configures the aggression of the stop when the pilot lets go of the sticks.
*   **`PHLD_BRAKE_RATE`**: How fast (deg/s) the drone can tilt back to stop its momentum.
*   **`PHLD_BRAKE_ANGLE`**: The maximum lean angle allowed during the braking phase.

## Parameter Breakdown

*   **`PHLD_BRAKE_RATE`**: Braking speed.
*   **`PHLD_BRAKE_ANGLE`**: Max braking tilt.

## Integration Guide
*   **Feel:** If PosHold feels too "slidey" when you release the sticks, increase `PHLD_BRAKE_RATE`.
*   **Safe Ops:** PosHold is excellent for FPV pilots who want a manual feel but need the drone to "stay put" if they take their hands off the controls.

## Developer Notes
*   **Library:** `ArduCopter/mode_poshold.cpp`.