# Airspeed Limits (AIRSPEED)

## Overview
The **AIRSPEED** parameter group (often aliased or related to `ARSPD_FBW_` parameters in the full parameter list) defines the **Flight Envelope** for ArduPlane's autonomous and assisted modes.

These limits are critical for the TECS (Total Energy Control System) controller. They tell the autopilot the safe range of speeds within which the aircraft can fly.
*   **Too Slow:** Risk of Stall.
*   **Too Fast:** Risk of Structural Failure (Vne) or Flutter.

## Key Concepts

### 1. Minimum Airspeed (`AIRSPEED_MIN`)
This is the "Floor" speed. In auto-throttle modes (Auto, Cruise, FBWB), the autopilot will apply maximum throttle and pitch down if necessary to prevent the airspeed from dropping below this value.
*   **Setting:** Should be set slightly above the stall speed of the airframe (e.g., 1.2x Stall Speed).

### 2. Maximum Airspeed (`AIRSPEED_MAX`)
This is the "Ceiling" speed. The autopilot will reduce throttle or pitch up to prevent exceeding this value.
*   **Setting:** Should be set below the structural limit of the airframe.

### 3. Cruise Speed (`TRIM_ARSPD_CM` or `AIRSPEED_CRUISE`)
(Related parameter) The target speed the autopilot tries to maintain during normal flight. It must lie between MIN and MAX.

## Parameter Breakdown

*   **`AIRSPEED_MIN`**: Minimum allowed airspeed (m/s).
*   **`AIRSPEED_MAX`**: Maximum allowed airspeed (m/s).

## Integration Guide

### Initial Tuning
1.  **Stall Test (Manual):** Fly high in manual mode. Reduce throttle and pull back elevator until the nose drops (stall). Note the speed.
2.  **Set MIN:** Set `AIRSPEED_MIN` to Stall Speed + 2-3 m/s.
3.  **High Speed Test:** Fly fast. Note the speed where the airframe feels stable.
4.  **Set MAX:** Set `AIRSPEED_MAX` to this safe top speed.

## Developer Notes
*   **Vehicle:** **ArduPlane** Only.
*   **Interaction:** These limits directly constrain the `AP_TECS` speed demand.
*   **Aliases:** In some firmware versions, these appear as `ARSPD_FBW_MIN` and `ARSPD_FBW_MAX`.