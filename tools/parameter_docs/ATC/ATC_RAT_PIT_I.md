---
layout: parameter
name: ATC_RAT_PIT_I
display_name: Pitch Axis Rate I Gain
description: Integral gain for the pitch rate controller. Corrects long-term steady-state errors, such as nose-heavy or tail-heavy imbalances.
default_value: 0.135
range: 0.01 2.0
units: 
group: ATC
visual_asset_id: atc_rat_pit_i_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L18
---

# Pitch Axis Rate I Gain (ATC_RAT_PIT_I)

## Description
`ATC_RAT_PIT_I` is the "automatic trim" for your drone's pitch axis. Its job is to remember and correct for persistent imbalances in the drone's weight distribution or aerodynamic drag.

If your drone is **nose-heavy** (e.g., you mounted a large camera on the front), the drone will naturally want to tilt forward. Without an I-term, you would have to constantly pull back on the stick to keep it level. The I-term "notices" that the drone keeps falling forward and slowly increases the power to the front motors until the drone stays level on its own.

*   **Low Value:** The drone will drift forward or backward in wind. It won't hold its pitch angle accurately during long movements.
*   **High Value:** The drone holds its pitch angle very strictly.
*   **Too High:** The drone will develop a slow "pitch wobble" as the integrator over-corrects and "hunts" for the perfect trim point.

## The Mathematics
The I-term accumulates the pitch rate error over time:

$$ \text{Out}_I += \int_0^t (\omega_{target} - \omega_{actual}) \cdot k_I \cdot dt $$

Where:
*   $k_I$ is `ATC_RAT_PIT_I`.
*   The result is constrained by `ATC_RAT_PIT_IMAX`.

**Longitudinal Stability:** Because most drones have their battery mounted on top/bottom and payloads on the front/back, the Pitch I-term usually has to work much harder than the Roll I-term.

## The Engineer's View
This parameter is the `_ki` member of the `_pid_rate_pitch` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_integrator += (error * _ki * dt);
_integrator = constrain_float(_integrator, -_kimax, _kimax);
```

ArduPilot's **Leakiness** logic ensures that the integrator doesn't stay wound up forever. When the drone is on the ground, the integrator is slowly decayed to zero to prevent a "jumpy" take-off.

## Tuning & Behavior
*   **Default Value:** 0.135 (Matches P-gain)
*   **Range:** 0.01 - 2.0
*   **Effect of Increasing:** Better tracking of forward velocity, less pitch drift in wind.
*   **Effect of Decreasing:** Drone feels more "fluid," but may lose its pitch target over long distances.

### Use Case Recommendations
*   **Nose-Mounted Gimbal (Cinematic):** **Increase to 0.2.** Heavier cameras on the nose require more I-term authority to maintain a stable, level horizon.
*   **Speed Runs:** **Increase to 0.25.** High aerodynamic drag at 60mph+ creates a massive torque trying to flip the drone; a strong I-term is required to fight this.
*   **Small Whoops / Micros:** **Keep Default.** Lightweight frames are usually well-balanced.

### Troubleshooting
*   **Scenario:** When you stop flying forward, the drone levels out, but then its nose slowly sinks by 2-3 degrees over the next few seconds.
    *   **Diagnosis:** `ATC_RAT_PIT_I` is too low. It isn't building up enough authority to fight the weight of the drone.
    *   **Fix:** Increase `ATC_RAT_PIT_I` by 0.02.