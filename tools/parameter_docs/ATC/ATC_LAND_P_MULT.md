---
layout: parameter
name: ATC_LAND_P_MULT
display_name: Landed Pitch Gain Multiplier
description: Reduces the pitch axis control gains specifically when the drone is on the ground. Prevents high-frequency forward/backward oscillations during touchdown.
default_value: 1.0
range: 0.25 1.0
units: 
group: ATC
visual_asset_id: atc_land_p_mult_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L131
---

# Landed Pitch Gain Multiplier (ATC_LAND_P_MULT)

## Description
`ATC_LAND_P_MULT` manages the stability of your drone's nose and tail during the critical landing phase. 

When your drone's landing gear hits the ground, the air resistance is replaced by solid mechanical contact. If your pitch gains are high, the drone might feel the impact of the ground and try to "stabilize" against it by pitching up or down. Because the ground is rigid, this creates a high-speed vibration loop that can cause the drone to "dance" or flip forward/backward on its gear.

This parameter allows you to automatically scale down the pitch authority the moment the landing detector is triggered.

*   **Set to 1.0 (Default):** No reduction. The drone maintains its full flight authority on the ground.
*   **Set to 0.5:** The drone's pitch gains are halved on touchdown. This makes the drone feel "heavy" and settled, preventing it from bobbing its head or flipping over.

## The Mathematics
The effective pitch gains are scaled by this multiplier ($M$) during the landing transition:

$$ \text{Gain}_{effective} = \text{Gain}_{flight} \cdot M $$ 

Where $M$ is `ATC_LAND_P_MULT`.

**Dynamic Transition:** ArduPilot ramps the gain down over a short period of time (defined by the attitude shaper) to avoid a sudden "step" in motor power that could itself trigger a bounce.

## The Engineer's View
This parameter is the `_land_pitch_mult` member in `AC_AttitudeControl`.

It is applied in `AC_AttitudeControl::landed_gain_reduction()`:

```cpp
// AC_AttitudeControl.cpp
Vector3f scale_mult = VECTORF_111 * (1.0 - _landed_gain_ratio) + Vector3f(_land_roll_mult, _land_pitch_mult, _land_yaw_mult) * _landed_gain_ratio;
set_PD_scale_mult(scale_mult);
set_angle_P_scale_mult(scale_mult);
```

This ensures that any nose-heavy or tail-heavy imbalances (which the I-term usually fights) don't result in a violent motor surge when the drone is physically constrained by the landing pad.

## Tuning & Behavior
*   **Default Value:** 1.0 (No reduction)
*   **Range:** 0.25 - 1.0
*   **Effect of Decreasing:** Drone becomes much more stable on the ground. Prevents "nose-dives" during auto-landing.
*   **Effect of Increasing:** Maintains full authority. Useful for landing on inclines (like a boat deck) where you must fight the tilt until the moment of disarm.

### Use Case Recommendations
*   **Cinematography (Gimbal Safety):** **Decrease to 0.5.** Ensures the drone stays perfectly flat and calm on the ground, protecting the gimbal from accidental "nose-bobs."
*   **Speed / Freestyle Quads:** **Keep at Default.** These frames are so light that they rarely suffer from ground resonance.
*   **Large Hybrid/Fixed-Wing VTOL:** **Decrease to 0.4.** High-inertia vehicles with large wings can catch the wind on the ground; reducing the gain prevents the motors from fighting that wind in a way that would over-stress the airframe.

### Troubleshooting
*   **Scenario:** On auto-landing, the drone touches down and then immediately "pitches forward" and strikes its front propellers on the ground.
    *   **Diagnosis:** Longitudinal Ground Resonance or I-term windup.
    *   **Fix:** Reduce `ATC_LAND_P_MULT` to 0.5.
    *   **Also check:** `ATC_THR_MIX_MIN`.