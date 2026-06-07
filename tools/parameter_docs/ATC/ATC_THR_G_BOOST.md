---
layout: parameter
name: ATC_THR_G_BOOST
display_name: Throttle-Gain Boost
description: Dynamically increases the attitude control gains (stiffness) when the throttle is rapidly changing. Helps maintain stability during aggressive vertical "punches" or descents.
default_value: 0.0
range: 0 1.0
units: 
group: ATC
visual_asset_id: atc_thr_g_boost_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L318
---

# Throttle-Gain Boost (ATC_THR_G_BOOST)

## Description
`ATC_THR_G_BOOST` is a dynamic "authority booster" for high-performance flight. 

Drones are most unstable when their motor speeds are changing rapidly—specifically during a sudden vertical "punch" (full throttle) or a rapid descent (low throttle). During these transients, the aerodynamics around the propellers are chaotic, and the drone needs extra "stiffness" to keep from wobbling. 

`ATC_THR_G_BOOST` monitors how fast your throttle is changing and automatically "turns up the volume" on your Roll and Pitch PID gains for a few milliseconds to ensure the drone stays perfectly level through the shock.

*   **Set to 0 (Default):** No boosting is applied. Gains stay constant.
*   **Set to 1.0:** The drone will double its attitude authority during rapid throttle movements.

## The Mathematics
The controller calculates the **Throttle Slew Rate** (how fast the PWM is changing). If the slew rate exceeds a threshold, the attitude gains are scaled:

$$ \text{Boost\_Scale} = 1.0 + (\text{ATC\_THR\_G\_BOOST} \cdot \text{Normalized\_Slew}) $$ 

**Effect:** If you have `ATC_THR_G_BOOST` set to 1.0 and you slam the throttle to 100%, your `ATC_RAT_RLL_P` and `ATC_ANG_RLL_P` might temporarily double in value to "lock" the drone's orientation during the acceleration.

## The Engineer's View
This parameter is the `_throttle_gain_boost` member in `AC_AttitudeControl_Multi`.

It is applied in `AC_AttitudeControl_Multi::update_throttle_gain_boost()`:

```cpp
// AC_AttitudeControl_Multi.cpp
if (_motors.get_throttle_slew_rate() > AC_ATTITUDE_CONTROL_THR_G_BOOST_THRESH) {
    const float pd_boost = constrain_float(_throttle_gain_boost + 1.0f, 1.0, 2.0);
    set_PD_scale_mult(Vector3f(pd_boost, pd_boost, 1.0f));

    const float angle_p_boost = constrain_float((_throttle_gain_boost + 1.0f) * (_throttle_gain_boost + 1.0f), 1.0, 4.0);
    set_angle_P_scale_mult(Vector3f(angle_p_boost, angle_p_boost, 1.0f));
}
```

Notice the **Quadratic Scaling** on the Angle P-gain (`angle_p_boost`). This is designed to provide massive "restoring force" during vertical maneuvers, keeping the drone perfectly flat even when the air is extremely turbulent.

## Tuning & Behavior
*   **Default Value:** 0.0 (Disabled)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** Much more stable "vertical punches." Reduced "nose-dipping" during rapid acceleration.
*   **Effect of Decreasing:** Smoother, more natural power transitions. Lower risk of high-frequency "chirping" during aggressive flight.

### Use Case Recommendations
*   **FPV Racing / Freestyle:** **Set to 0.5 - 1.0.** Essential for maintaining attitude precision during rapid directional changes and "split-S" maneuvers.
*   **Heavy Lift Multirotors:** **Set to 0.2.** Large drones have sluggish motor response; a small boost helps them "dig in" when the pilot requests more power.
*   **Cinematography:** **Keep at 0.0.** You want the drone to be smooth; sudden gain increases can cause tiny visible twitches in the video.

### Troubleshooting
*   **Scenario:** Drone "oscillates" or vibrates specifically during the first 0.5 seconds of a full-throttle climb.
    *   **Diagnosis:** `ATC_THR_G_BOOST` is set too high, pushing the gains past the point of stability during the power-up.
    *   **Fix:** Reduce `ATC_THR_G_BOOST` to 0.25 or 0.0.