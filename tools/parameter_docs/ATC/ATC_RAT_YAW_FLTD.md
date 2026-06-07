---
layout: parameter
name: ATC_RAT_YAW_FLTD
display_name: Yaw Axis Rate D-Term Filter
description: Low-pass filter frequency (in Hz) applied specifically to the derivative (D) term of the yaw controller.
default_value: 0.0
range: 5 50
units: Hz
group: ATC
visual_asset_id: atc_rat_yaw_fltd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L59
---

# Yaw Axis Rate D-Term Filter (ATC_RAT_YAW_FLTD)

## Description
`ATC_RAT_YAW_FLTD` is a specialized filter for the drone's yaw damping. In a PID loop, the **Derivative (D)** term reacts to the *rate of change* of rotation. In the yaw axis, this is a very high-noise signal because the Z-axis of the gyroscope is directly exposed to the mechanical vibration of the entire frame twisting.

*   **Note:** Since most multirotors use a yaw D-gain (`ATC_RAT_YAW_D`) of **0.0**, this filter is typically inactive. 
*   **Purpose:** If you do use yaw damping (common on Tricopters), this filter prevents that damping from amplifying motor noise into a high-frequency "chatter."

## The Mathematics
The D-term calculates the derivative of the yaw error and then passes it through this low-pass filter:

$$ D_{filtered} = D_{prev} + \alpha \cdot \left( \frac{E - E_{prev}}{dt} - D_{prev} \right) $$

Where the filter coefficient $\alpha$ is derived from `ATC_RAT_YAW_FLTD` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

## The Engineer's View
This parameter maps to `_filt_D_hz` in the `_pid_rate_yaw` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    _derivative = _last_derivative + (dt / (_filt_D_hz + dt)) * (derivative - _last_derivative);
}
```

Because yaw torque is inherently slow to develop in multirotors, this filter can be set very low (5-10Hz) to ensure absolute silence in the motor output without significantly affecting the control feel.

## Tuning & Behavior
*   **Default Value:** 0.0 (Internal auto-selection, usually matching the error filter)
*   **Range:** 5.0 - 50.0 Hz
*   **Effect of Increasing:** Allows for more aggressive yaw damping (crisper turn stops).
*   **Effect of Decreasing:** Quieter motor operation, but the yaw damper will be less effective at stopping "bounces" after a spin.

### Use Case Recommendations
*   **Standard Multirotor:** **Keep at 0.0.** No need to tune this if your yaw D-gain is 0.
*   **Tricopters / Tilt-Rotors:** **Set to 10.0 - 15.0 Hz.** Mechanical yaw systems are much more sensitive to noise; a low D-filter frequency is essential for servo longevity.
*   **Racing Drones:** **Set to 20.0 Hz.** If using yaw damping, racers prefer a higher filter frequency to keep the tail feeling "electric" and instant.

### Troubleshooting
*   **Scenario:** You increased `ATC_RAT_YAW_D` and now the drone's motors sound like they are "scratching" or "grinding" during yaw turns.
    *   **Diagnosis:** D-term noise from the vertical axis.
    *   **Fix:** Reduce `ATC_RAT_YAW_FLTD` to 10.0 Hz.