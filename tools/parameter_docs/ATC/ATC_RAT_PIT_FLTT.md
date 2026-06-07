---
layout: parameter
name: ATC_RAT_PIT_FLTT
display_name: Pitch Axis Rate Target Filter
description: Low-pass filter frequency (in Hz) applied to the pitch rate setpoint. Smooths out sudden "steps" in the commanded rotation speed from the pilot or autopilot.
default_value: 0.0
range: 0 100
units: Hz
group: ATC
visual_asset_id: atc_rat_pit_fltt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L47
---

# Pitch Axis Rate Target Filter (ATC_RAT_PIT_FLTT)

## Description
`ATC_RAT_PIT_FLTT` smooths the commands sent to the drone's pitch rate controller. While other filters (like `FLTE`) clean up noise from the **Sensors**, this filter cleans up "jumps" from the **Software**.

When a pilot moves the pitch stick or an autopilot changes the flight path, the target rotation rate might change in a sudden "step." These sharp edges can cause the drone to "kick" its nose up or down violently. This filter rounds off those corners, ensuring the drone accelerates into its pitch rotation gracefully rather than with a mechanical shock.

*   **Low Frequency (e.g., 10Hz):** Very smooth, "organic" flight feel. Pitch commands are softened.
*   **High Frequency (e.g., 40Hz):** Instant response. The drone follows every tiny pitch command perfectly.
*   **Disabled (0):** The target rate is unfiltered. Maximum responsiveness, but potential for mechanical "ringing."

## The Mathematics
This is a single-pole low-pass filter applied to the target rate ($\omega_{target}$):

$$ \omega_{target\_filtered} = \omega_{target\_prev} + \alpha \cdot (\omega_{target\_raw} - \omega_{target\_prev}) $$

Where $\alpha$ is derived from `ATC_RAT_PIT_FLTT` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

**Effect:** This acts as a "softener" for the pitch stick. A 20Hz filter frequency corresponds to a time constant of about 8 milliseconds—enough to save your drone from resonant frame vibrations during hard stops.

## The Engineer's View
This parameter maps to `_filt_T_hz` in the `_pid_rate_pitch` object.

It is applied at the very beginning of the PID loop in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_target += (target - _target) * get_filt_T_alpha(dt);
```

By filtering the target *at the source*, ArduPilot ensures that the Feed-Forward (`RAT_PIT_FF`) and P-terms don't produce a massive, discontinuous spike when the command changes.

## Tuning & Behavior
*   **Default Value:** 0.0 (Disabled / Loop rate)
*   **Range:** 0.0 - 100.0 Hz
*   **Effect of Increasing:** Snappier, more "direct" stick feel in the pitch axis.
*   **Effect of Decreasing:** Smoother cinematic forward/backward transitions. Essential for vehicles with long arms that can flex under sudden torque.

### Use Case Recommendations
*   **Standard Build:** **Keep at 0.0.** ArduPilot's internal path planning handles most command smoothing automatically.
*   **High-End Cinematography:** **Set to 15.0 Hz.** Adds a professional "weighted" feel to the pitch axis, making forward moves look more like a heavy camera crane.
*   **Racing / FPV:** **Keep at 0.0.** Minimum latency is priority for high-speed maneuvering.

### Troubleshooting
*   **Scenario:** Drone makes a "clunk" sound specifically when you suddenly release the pitch stick after a forward dash.
    *   **Diagnosis:** Discontinuous target rate is causing a motor current spike (mechanical ringing).
    *   **Fix:** Set `ATC_RAT_PIT_FLTT` to 20.0 Hz.