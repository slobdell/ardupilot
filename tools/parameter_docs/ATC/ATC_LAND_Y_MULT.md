---
layout: parameter
name: ATC_LAND_Y_MULT
display_name: Landed Yaw Gain Multiplier
description: Reduces the yaw axis control gains specifically when the drone is on the ground. Prevents tail oscillation and "spinning out" during touchdown.
default_value: 1.0
range: 0.25 1.0
units: 
group: ATC
visual_asset_id: atc_land_y_mult_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L137
---

# Landed Yaw Gain Multiplier (ATC_LAND_Y_MULT)

## Description
`ATC_LAND_Y_MULT` handles the drone's heading stability during the landing phase. 

When a multirotor touches the ground, it often experiences "Yaw Torque" from friction between the legs and the earth. If your yaw gains are high, the drone will try to fight this friction to keep its nose straight. This can lead to a violent "spinning" or "twisting" vibration as the drone tries to yaw against the immovable ground.

This parameter allows the flight controller to automatically lower its yaw authority the moment the landing gear makes contact.

*   **Set to 1.0 (Default):** No reduction. The drone fights to maintain its heading even on the ground.
*   **Set to 0.5:** The drone's yaw authority is cut in half on the ground. This allows the drone to "relax" its heading slightly to match the ground friction, preventing mechanical stress on the frame and landing gear.

## The Mathematics
The effective yaw gains are scaled by this multiplier ($M$) during the landing sequence:

$$ \text{Gain}_{effective} = \text{Gain}_{flight} \cdot M $$ 

Where $M$ is `ATC_LAND_Y_MULT`.

**Safety Note:** Unlike Roll and Pitch, where a loss of control means a flip, a loss of Yaw control on the ground usually just means the nose rotates by a few degrees. Therefore, `ATC_LAND_Y_MULT` can often be set lower than the other multipliers without significant risk.

## The Engineer's View
This parameter is the `_land_yaw_mult` member in `AC_AttitudeControl`.

It is applied in `AC_AttitudeControl::landed_gain_reduction()`:

```cpp
// AC_AttitudeControl.cpp
Vector3f scale_mult = VECTORF_111 * (1.0 - _landed_gain_ratio) + Vector3f(_land_roll_mult, _land_pitch_mult, _land_yaw_mult) * _landed_gain_ratio;
set_PD_scale_mult(scale_mult);
set_angle_P_scale_mult(scale_mult);
```

This logic ensures that any motor torque imbalances don't cause the drone to "pivot" or "spin out" violently when one leg has more friction with the ground than the others.

## Tuning & Behavior
*   **Default Value:** 1.0 (Standard)
*   **Range:** 0.25 - 1.0
*   **Effect of Decreasing:** Drone becomes much "lazier" in its heading on the ground. Prevents tail-induced vibrations during touchdown.
*   **Effect of Increasing:** Maintains full heading hold. Useful for landing on moving or slippery surfaces where the drone must maintain its heading relative to the vehicle below it.

### Use Case Recommendations
*   **Standard Multirotor:** **Set to 0.5 - 0.7.** This is generally safer and reduces the "growling" sound often heard when multirotors land on concrete.
*   **Landing on Moving Boats:** **Keep at 1.0.** You want the drone to fight the friction and stay aligned with the boat's direction until it is fully disarmed.
*   **Tricopters (Servo Yaw):** **Set to 0.4.** Servos can easily strip their gears if they try to yaw against ground friction; reducing the gain is critical for mechanical protection.

### Troubleshooting
*   **Scenario:** On landing, the drone "twists" its legs or frame violently just before the motors stop.
    *   **Diagnosis:** Yaw ground resonance or motor torque spikes.
    *   **Fix:** Reduce `ATC_LAND_Y_MULT` to 0.5.