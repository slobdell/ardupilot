# Fly-By-Wire B Mode (FBWB)

## Overview
The **FBWB** parameter group configures the behavior of the **Fly-By-Wire B** (FBWB) flight mode in **ArduPlane**.

FBWB is a "Pilot Assist" mode where the autopilot maintains a constant altitude and airspeed when sticks are centered.
*   **Roll Stick:** Commands a bank angle (stiffness/turn).
*   **Pitch Stick:** Commands a **climb or descent rate**, not a pitch angle.
*   **Throttle Stick:** Commands an **airspeed**, not a raw motor power.

## Key Concepts

### 1. Climb Rate (`FBWB_CLIMB_RATE`)
Defines how fast (m/s) the aircraft will climb when the pilot pulls the pitch stick all the way back.
*   **Behavior:** The autopilot uses the `TECS` (Total Energy Control System) to manage pitch and throttle together to achieve this rate.

### 2. Stick Logic (`FBWB_ELEV_REV`)
Allows reversing the sense of the elevator stick for altitude control.
*   **0 (Normal):** Back on stick = Climb.
*   **1 (Reversed):** Back on stick = Descend.

## Parameter Breakdown

*   **`FBWB_CLIMB_RATE`**: Maximum climb/descent rate (m/s).
*   **`FBWB_ELEV_REV`**: Reverse pitch stick sense for altitude.

## Integration Guide
*   **Usage:** FBWB is ideal for smooth cruising. It is essentially "Manual with an autopilot safety net."
*   **Tuning:** Ensure your `TECS_` parameters (Total Energy) are well-tuned before relying heavily on FBWB climb rates.

## Developer Notes
*   **Library:** `ArduPlane/mode_fbwb.cpp`.