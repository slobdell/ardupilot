# Pullup Configuration (PUP)

## Overview
The **PUP** parameter group configures the **Pullup** library for **ArduPlane**. This is an advanced safety feature designed for high-altitude aircraft or specialized drop-launch missions (where the plane is dropped from another vehicle).

The pullup logic handles the transition from a vertical freefall or steep dive into stable level flight without exceeding the structural G-load limits of the airframe.

## Key Concepts

### 1. Freefall Recovery
When a plane is dropped, it has no initial airspeed and the control surfaces are ineffective.
*   **`PUP_ENABLE`**: Master switch.
*   **`PUP_ARSPD_START`**: The airspeed (m/s) the autopilot must reach before it attempts to pull the nose up.

### 2. G-Load Protection (`PUP_NG_LIM`)
Pulling up too sharply at high speed can snap the wings.
*   **`PUP_NG_LIM`**: Sets the maximum vertical G-load (in Gs) allowed during the recovery maneuver. The autopilot will modulate the elevator to stay within this limit.

## Parameter Breakdown

*   **`PUP_PITCH_START`**: The pitch angle at which the system starts the pullup logic.
*   **`PUP_ELEV_OFS`**: A constant elevator offset used to initiate the nose-up movement.

## Integration Guide
*   **Special Missions:** This is primarily used for atmospheric research drones or high-altitude balloon launches.
*   **Simulation:** **Test in SITL** drop-launch scenarios before attempting a real drop mission.

## Developer Notes
*   **Library:** `ArduPlane/pullup.cpp`.