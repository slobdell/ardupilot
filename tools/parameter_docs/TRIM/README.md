# Neutral Trim Configuration (TRIM)

## Overview
The **TRIM** parameter group (specifically `TRIM_THROTTLE` or `THROTTLE_CRUISE`) defines the steady-state cruise values for the propulsion system.

## Key Concepts

### 1. Cruise Throttle
*   **`TRIM_THROTTLE`**: (ArduPlane/Rover) The percentage of throttle required to maintain `CRUISE_SPEED` in level flight.
*   **Usage:** Provides the FeedForward baseline for the speed controller. If set correctly, the drone will maintain speed perfectly when you switch from Manual to an autonomous mode.

## Developer Notes
*   **Library:** `libraries/AP_TECS`, `libraries/AR_AttitudeControl`.
*   **See Also:** [CRUISE](../CRUISE/README.md) for related speed settings.