--- 
layout: parameter
name: ATC_RAT_YAW_D
display_name: Yaw Axis Rate D Gain
description: Derivative gain for the yaw rate controller. Acts as a "damper" to stop tail rotation quickly and prevent the drone from overshooting its heading.
default_value: 0.0
range: 0.0 0.02
units: 
group: ATC
visual_asset_id: atc_rat_yaw_d_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L23
---

# Yaw Axis Rate D Gain (ATC_RAT_YAW_D)

## Description
`ATC_RAT_YAW_D` is the "brakes" for your drone's rotation. In physics, the **Derivative (D)** term looks at how fast the rotation is changing and provides a counter-force to slow it down as it approaches the target.

In the yaw axis, this parameter is very rarely used. Because multirotors yaw using torque reaction (which is relatively weak), the air itself provides enough natural damping to stop the drone from spinning. For most multirotors, this parameter is kept at **0.0**. However, for specialized frames or vehicles with very high yaw authority (like Tricopters or single-motor helicopters), a small amount of D-gain can help stop a fast spin without any bounce-back.

*   **Low Value (0.0):** Standard behavior. The drone relies on natural air resistance and the P-gain to stop yawing.
*   **High Value:** The drone stops its yaw turns with mechanical precision. No overshoot.
*   **Too High:** The drone will emit high-frequency "chatter" or buzzing from the tail, as the D-term over-reacts to tiny gyro vibrations. This can damage motor bearings.

## The Mathematics
The D-term is proportional to the rate of change of the yaw rate error:

$$ \text{Out}_D = k_D \cdot \frac{d(\omega_{yaw\_target} - \omega_{yaw\_actual})}{dt} $$

Where:
*   $k_D$ is `ATC_RAT_YAW_D`.
*   The derivative is filtered by `ATC_RAT_YAW_FLTD`.

**Intuition:** If the tail is swinging very fast toward its heading, the D-term pushes *against* that speed to make the landing at the target heading as soft as possible.

## The Engineer's View
This parameter is the `_kd` member of the `_pid_rate_yaw` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    _derivative = filtered_derivative;
}
return ... + _derivative * _kd;
```

In `AC_AttitudeControl_Multi`, the yaw D-term is often bypassed entirely if the gain is set to 0, which saves precious CPU cycles for the more critical Roll and Pitch loops.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard Quad)
*   **Range:** 0.0 - 0.02
*   **Effect of Increasing:** Crisper stops at the end of yaw turns. Better stability during high-speed forward flight.
*   **Effect of Decreasing:** Maximum smoothness. Lower risk of motor vibration.

### Use Case Recommendations
*   **Standard Multirotor:** **Keep at 0.0.** It is almost never needed for basic stability.
*   **Tricopters (Servo Yaw):** **Set to 0.005 - 0.01.** Servos are much faster and more powerful than torque reaction; they need damping to prevent the mechanical tail from "wagging" during stops.
*   **Heavy Lift Octocopter:** **Increase to 0.002.** Massive frames have high yaw inertia and may "coast" past their heading; a tiny amount of D-gain helps bring them to a controlled stop.

### Troubleshooting
*   **Scenario:** You perform a fast 360-degree spin, and when you let go of the stick, the tail "overshoots" and then bounces back by 5 degrees.
    *   **Diagnosis:** Inadequate yaw damping.
    *   **Fix:** Increase `ATC_RAT_YAW_D` by 0.001 (start very small!).