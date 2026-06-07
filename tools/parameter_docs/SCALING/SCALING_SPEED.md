---
layout: parameter
name: SCALING_SPEED
display_name: "Speed scaling reference speed"
description: "The airspeed where the control surface deflection is considered 'normal' (Scaling = 1.0)."
default_value: 15.0
range: 0 50
units: "m/s"
group: SCALING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L660
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Attitude.cpp#L17
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Speed scaling reference speed (SCALING_SPEED)

## Description
This parameter sets the "Baseline Airspeed" for the control surface scaling system. 

As a fixed-wing aircraft flies faster, its control surfaces (ailerons, elevator, rudder) become more effective, generating more force for the same amount of movement. To prevent the aircraft from becoming twitchy or oscillating at high speeds, ArduPilot automatically reduces the control surface movement as speed increases.

`SCALING_SPEED` is the speed at which your tuned PID gains are applied exactly as written (Multiplier = 1.0).
*   **Faster than `SCALING_SPEED`:** Surfaces move LESS than the PID requests (Multiplier < 1.0).
*   **Slower than `SCALING_SPEED`:** Surfaces move MORE than the PID requests (Multiplier > 1.0).

**Critical:** This value is typically set to your **Cruise Speed** or the speed at which you performed **Autotune**.

## The Mathematics
The system calculates a scaling factor ($K_{scale}$) that is applied to the P, I, and D terms of the attitude controllers.

$$ K_{scale} = \frac{SCALING\_SPEED}{V_{true}} $$

Where $V_{true}$ is the current True Airspeed (TAS).

*   If $V_{true} = SCALING\_SPEED$, $K_{scale} = 1.0$
*   If $V_{true} = 2 \times SCALING\_SPEED$, $K_{scale} = 0.5$ (Half deflection for same error).

This inverse-linear relationship is derived from the physics of steady-state rate control, where the required deflection for a given turn rate scales inversely with velocity ($\delta \propto \frac{p}{V}$).

## The Engineer's View
In `Plane::calc_speed_scaler()` (`ArduPlane/Attitude.cpp`), this scaler is computed and then constrained.
*   **Upper Limit:** The scaler is capped at roughly `2.0` (or calculated based on `AIRSPEED_MIN`) to prevent excessive surface throw at stall speeds.
*   **Lower Limit:** The scaler is floored at `0.5` (or calculated based on `AIRSPEED_MAX`) to prevent loss of control at high speeds.
*   **No Airspeed Sensor:** If no airspeed sensor is present, the system estimates speed scaling using `THROTTLE_CRUISE` vs actual Throttle, applying a square root approximation: $Scale = \sqrt{\frac{THROTTLE\_CRUISE}{Throttle_{out}}}$.

## Tuning & Behavior
*   **Default Value:** 15.0 m/s
*   **Range:** 5 to 50 m/s
*   **Effect of Changing:**
    *   **Increasing `SCALING_SPEED`:** Makes the surfaces move **more** at all speeds (higher effective gain).
    *   **Decreasing `SCALING_SPEED`:** Makes the surfaces move **less** at all speeds (lower effective gain).
*   **Golden Rule:** If you change `SCALING_SPEED` after tuning, you invalidate your tune. You must re-tune (Autotune) or manually scale your P/I/D gains by the ratio of the change.

