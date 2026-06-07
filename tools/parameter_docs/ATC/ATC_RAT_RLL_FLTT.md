---
layout: parameter
name: ATC_RAT_RLL_FLTT
display_name: Roll Axis Rate Target Filter
description: Low-pass filter frequency (in Hz) applied to the roll rate setpoint. Smooths out sudden "steps" in the commanded rotation speed from the pilot or autopilot.
default_value: 0.0
range: 0 100
units: Hz
group: ATC
visual_asset_id: atc_rat_rll_fltt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L47
---

# Roll Axis Rate Target Filter (ATC_RAT_RLL_FLTT)

## Description
`ATC_RAT_RLL_FLTT` smooths the commands sent to the drone's roll rate controller. While other filters (like `FLTE`) clean up noise from the **Sensors**, this filter cleans up "jumps" from the **Software**.

When a pilot moves the stick or an autopilot changes the flight path, the target rotation rate might change in a sudden "step" (e.g., from 0 deg/s to 50 deg/s in one loop). These sharp edges can cause the motors to kick violently. This filter rounds off those corners, ensuring the drone accelerates into its rotation gracefully rather than with a mechanical shock.

*   **Low Frequency (e.g., 10Hz):** Very smooth, "organic" flight feel. Commands are softened.
*   **High Frequency (e.g., 40Hz):** Instant response. The drone follows every tiny twitch of the pilot's fingers.
*   **Disabled (0):** The target rate is unfiltered. Maximum responsiveness, but potential for mechanical "ringing."

## The Mathematics
This is a low-pass filter applied to the target rate ($\omega_{target}$):

$$ \omega_{target\_filtered} = \omega_{target\_prev} + \alpha \cdot (\omega_{target\_raw} - \omega_{target\_prev}) $$

Where $\alpha$ is derived from `ATC_RAT_RLL_FLTT` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

**Effect:** This effectively acts as a "stick smoothing" parameter. A 20Hz filter frequency corresponds to a time constant of about 8 milliseconds—unnoticeable to most pilots but enough to save your frame from resonant vibration.

## The Engineer's View
This parameter maps to `_filt_T_hz` in the `_pid_rate_roll` object.

It is applied at the entry point of the PID loop in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_target += (target - _target) * get_filt_T_alpha(dt);
```

By filtering the target *at the start* of the loop, ArduPilot ensures that the Feed-Forward (`RAT_RLL_FF`) and P-terms don't produce a massive, discontinuous spike when the command changes.

## Tuning & Behavior
*   **Default Value:** 0.0 (Disabled / Loop rate)
*   **Range:** 0.0 - 100.0 Hz
*   **Effect of Increasing:** Snappier, more "direct" stick feel. Better for racing.
*   **Effect of Decreasing:** Smoother cinematic transitions. Essential for vehicles with very large, high-torque motors that can be damaged by sudden "kicks."

### Use Case Recommendations
*   **Standard build:** **Keep at 0.0.** The input shaping logic in ArduPilot usually handles command smoothing perfectly.
*   **Heavy Lift / Long Endurance:** **Set to 10.0 Hz.** Reduces the "impact" of stick commands on the frame and battery, potentially increasing flight time and frame longevity.
*   **FPV Freestyle:** **Keep at 0.0.** Pilots generally prefer the absolute minimum latency between their brain and the motors.

### Troubleshooting
*   **Scenario:** Drone makes a "clunk" or "knock" sound specifically when you suddenly move the roll stick to its limit.
    *   **Diagnosis:** Discontinuous target rate is causing a motor current spike.
    *   **Fix:** Set `ATC_RAT_RLL_FLTT` to 20.0 Hz.