# Total Energy Control System (TECS)

## Overview
The **TECS** parameter group configures the **Total Energy Control System**. This is the core altitude and airspeed management algorithm for **ArduPlane** (and QuadPlane).

TECS is a sophisticated "Energy Balancer." It treats the aircraft's energy as the sum of its Potential Energy (Altitude) and Kinetic Energy (Airspeed). It then uses the Throttle to change the *total* energy and the Elevator to *exchange* energy between altitude and airspeed.

## Key Concepts

### 1. Energy Balancing
If the plane is too slow and too low, TECS increases throttle (add energy).
If the plane is too fast but too low, TECS pulls the nose up (exchange kinetic energy for potential energy).

### 2. Limits (`TECS_CLMB_MAX`, `TECS_SINK_MAX`)
Defines the physical performance envelope of the aircraft.
*   **`CLMB_MAX`**: The steepest sustained climb rate the motor can provide (m/s).
*   **`SINK_MAX`**: The fastest safe descent rate (m/s).

### 3. Weighting (`TECS_SPDWEIGHT`)
Defines the priority between speed and altitude.
*   **1.0 (Default):** Equal priority.
*   **2.0:** Prioritize Airspeed (essential for preventing stalls).
*   **0.0:** Prioritize Altitude (glide slope tracking).

### 4. Synthetic Airspeed (`TECS_SYNAIRSPEED`)
Allows the plane to fly without a pitot tube by estimating airspeed using GPS ground speed and a wind model.

## Parameter Breakdown

*   **`TECS_TIME_CONST`**: The overall responsiveness of the controller (seconds). Smaller = Aggressive.
*   **`TECS_PTCH_DAMP`**: Damping for pitch movements during energy exchange.
*   **`TECS_FLARE_HGT`**: Altitude to begin the landing flare.

## Integration Guide
1.  **Preparation:** Ensure your `AIRSPEED_MIN/MAX` and `THROTTLE_CRUISE` are set correctly.
2.  **Tuning:** If the plane "porpoises" (oscillates altitude) during a mission, **increase** `TECS_TIME_CONST`.
3.  **No Pitot:** If you don't have an airspeed sensor, set `TECS_SYNAIRSPEED = 1`.

## Developer Notes
*   **Library:** `libraries/AP_TECS`.
*   **Mathematics:** Based on the principle of work-energy. The controller minimizes the error in total energy and energy balance.