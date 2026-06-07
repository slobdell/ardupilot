---
layout: parameter
name: ATC_RAT_YAW_FLTT
display_name: Yaw Axis Rate Target Filter
description: Low-pass filter frequency (in Hz) applied to the yaw rate setpoint. Smooths out sudden "steps" in the commanded rotation speed from the pilot or autopilot.
default_value: 0.0
range: 0 50
units: Hz
group: ATC
visual_asset_id: atc_rat_yaw_fltt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L47
---

# Yaw Axis Rate Target Filter (ATC_RAT_YAW_FLTT)

## Description
`ATC_RAT_YAW_FLTT` smooths the yaw commands sent into the drone's rate controller. While other filters (like `FLTE`) clean up noise from the **Sensors**, this filter cleans up "jumps" from the **Software**.

When a pilot moves the yaw stick or an autopilot changes the heading during a mission, the target rotation rate might change in a sudden "step." Since yaw torque is relatively weak in multirotors, these sudden steps can cause the drone to "lurch" or create a noticeable jerk in the tail. This filter rounds off those corners, ensuring the drone accelerates into its turn gracefully rather than with a mechanical shock.

*   **Low Frequency (e.g., 5Hz):** Very smooth, "lazy" tail movement. Excellent for cinematography.
*   **High Frequency (e.g., 20Hz):** Instant response to stick inputs.
*   **Disabled (0):** The target rate is unfiltered. Maximum responsiveness, but potential for "robotic" and jerky tail movements.

## The Mathematics
This is a single-pole low-pass filter applied to the target rate ($\omega_{target}$):

$$ \omega_{target\_filtered} = \omega_{target\_prev} + \alpha \cdot (\omega_{target\_raw} - \omega_{target\_prev}) $$

Where $\alpha$ is derived from `ATC_RAT_YAW_FLTT` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

**Effect:** This filter effectively limits the "acceleration" of the yaw command. A 10Hz filter frequency corresponds to a time constant of about 16 milliseconds—enough to remove the perceived "jerk" from digital stick inputs.

## The Engineer's View
This parameter maps to `_filt_T_hz` in the `_pid_rate_yaw` object.

It is applied at the very entry point of the PID loop in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_target += (target - _target) * get_filt_T_alpha(dt);
```

By filtering the target *at the start* of the loop, ArduPilot ensures that the Feed-Forward (`RAT_YAW_FF`) doesn't produce a massive, discontinuous torque spike when the pilot's stick position changes.

## Tuning & Behavior
*   **Default Value:** 0.0 (Disabled / Loop rate)
*   **Range:** 0.0 - 50.0 Hz
*   **Effect of Increasing:** Snappier, more "connected" feel to the yaw stick.
*   **Effect of Decreasing:** Smoother cinematic panning. Reduces mechanical stress on large vehicles.

### Use Case Recommendations
*   **Standard Build:** **Keep at 0.0.** Standard ArduPilot input shaping handles this perfectly.
*   **Professional Photography (Smooth Pans):** **Set to 5.0 - 10.0 Hz.** Ensures that every camera pan starts and ends with a professional-looking "ease-in" and "ease-out" effect.
*   **Heavy Industrial / Cargo Drone:** **Set to 5.0 Hz.** Reduces the torsional stress on the long motor arms when initiating a turn.

### Troubleshooting
*   **Scenario:** Drone makes a faint "chirp" sound every time you suddenly move the yaw stick.
    *   **Diagnosis:** Discontinuous target rate is causing a torque transient.
    *   **Fix:** Set `ATC_RAT_YAW_FLTT` to 10.0 Hz.