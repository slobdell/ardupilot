---
layout: parameter
name: ATC_LAND_R_MULT
display_name: Landed Roll Gain Multiplier
description: Reduces the roll axis control gains specifically when the drone is on the ground. Prevents high-frequency oscillations and "ground shakes" during touchdown.
default_value: 1.0
range: 0.25 1.0
units: 
group: ATC
visual_asset_id: atc_land_r_mult_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L125
---

# Landed Roll Gain Multiplier (ATC_LAND_R_MULT)

## Description
`ATC_LAND_R_MULT` is a "de-tuning" parameter for the landing phase. 

Your drone's PID gains are tuned for flight (where the drone is surrounded by air). When the drone touches the ground, the physics change instantly. The rigid ground acts like a massive spring. If your roll gains are high, the drone might feel a tiny vibration from the ground and try to "stabilize" against it. This creates a feedback loop known as **Ground Resonance**, where the drone starts shaking violently or "hopping" from side to side on its landing gear.

This parameter allows you to automatically lower your roll authority the moment the landing gear touches the earth.

*   **Set to 1.0 (Default):** No reduction. The drone stays at full authority. Use this if your drone is very heavy and rigid.
*   **Set to 0.5:** The drone's roll gains are cut in half on the ground. Makes for much "quieter," safer landings.

## The Mathematics
The effective roll gains ($P$, $I$, $D$) are scaled by this multiplier ($M$) when the landing detector is active:

$$ \text{Gain}_{effective} = \text{Gain}_{flight} \cdot M $$ 

Where $M$ is `ATC_LAND_R_MULT`.

**Interpolation:** ArduPilot doesn't just "snap" the gain down. It uses a transition logic (tied to `ATC_INPUT_TC`) to smoothly ramp the gains down as the drone settles onto its gear.

## The Engineer's View
This parameter is the `_land_roll_mult` member in `AC_AttitudeControl`.

It is applied in `AC_AttitudeControl::landed_gain_reduction()`:

```cpp
// AC_AttitudeControl.cpp
Vector3f scale_mult = VECTORF_111 * (1.0 - _landed_gain_ratio) + Vector3f(_land_roll_mult, _land_pitch_mult, _land_yaw_mult) * _landed_gain_ratio;
set_PD_scale_mult(scale_mult);
set_angle_P_scale_mult(scale_mult);
```

This logic ensures that both the **Outer Angle Loop** and the **Inner Rate Loop** are softened, preventing any software-driven oscillations from reaching the motors while the drone is physically constrained by the ground.

## Tuning & Behavior
*   **Default Value:** 1.0 (Standard)
*   **Range:** 0.25 - 1.0
*   **Effect of Decreasing:** Drone becomes much "lazier" and more stable on the ground. Prevents tip-overs during auto-landings.
*   **Effect of Increasing:** Maximum authority on touchdown. Useful for "hard" landings on uneven or rocky terrain where you must fight to stay upright.

### Use Case Recommendations
*   **Lightweight Racers / Carbon Frames:** **Decrease to 0.5 - 0.7.** These frames are very stiff and prone to ground resonance. Lowering the gain makes the drone "stick" to the ground.
*   **Drones with Long, Springy Legs:** **Decrease to 0.4.** Springy legs amplify vibrations; reducing the gain is essential to keep the drone from "pogo-sticking."
*   **Heavy Industrial Drones:** **Keep at 1.0.** High inertia usually dampens ground vibrations naturally.

### Troubleshooting
*   **Scenario:** On every landing, the drone touches down and then starts a rapid "shiver" or vibration that won't stop until it disarms.
    *   **Diagnosis:** Ground Resonance. The PID loops are too fast for the physical contact with the earth.
    *   **Fix:** Reduce `ATC_LAND_R_MULT` and `ATC_LAND_P_MULT` to 0.6.