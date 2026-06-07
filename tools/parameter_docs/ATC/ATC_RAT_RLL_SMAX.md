---
layout: parameter
name: ATC_RAT_RLL_SMAX
display_name: Roll Axis Rate Slew Rate Limit
description: Limits the maximum rate of change of the motor output requested by the roll rate controller. Prevents high-frequency motor oscillations and protects ESCs from extreme current spikes.
default_value: 0.0
range: 0 200
units: 
group: ATC
visual_asset_id: atc_rat_rll_smax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L67
---

# Roll Axis Rate Slew Rate Limit (ATC_RAT_RLL_SMAX)

## Description
`ATC_RAT_RLL_SMAX` is a protective "governor" for your drone's power delivery. A **Slew Rate** is a limit on how fast a signal can change over time. 

In the roll controller, if the PID loop calculates that it needs to jump from 10% motor power to 100% motor power instantly (due to noise, a prop strike, or a violent gust), the motors and ESCs will experience a massive, destructive spike in current. This parameter rounds off those spikes, ensuring that the motor command always increases or decreases at a rate your hardware can safely handle.

*   **Low Value:** Flight feels extremely soft and "buttery." Motors will sound very smooth.
*   **High Value:** Allows the motors to reach their target power as fast as possible.
*   **Too High:** Risk of "motor chirping" or ESC failure due to extreme current transients.
*   **Disabled (0):** The software does not limit the rate of change of the motor command.

## The Mathematics
The slew limit acts as a "speed limit" for the motor output signal ($O$):

$$ |O_{new} - O_{prev}| \leq SMAX \cdot dt $$

If the calculated change in output exceeds $SMAX$, ArduPilot automatically reduces the P and D gains of the rate loop for that specific cycle to keep the command within the limit:

$$ \text{Gain Reduction Factor} = \frac{SMAX}{\text{Calculated Rate}} $$

## The Engineer's View
This parameter maps to `_slew_rate_max` in the `_pid_rate_roll` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(_slew_rate_max)) {
    _pid_info.slew_rate = (P + D - _last_out_pd) / dt;
    if (fabsf(_pid_info.slew_rate) > _slew_rate_max) {
        // Dynamically lower P and D for this loop cycle
        float scale = _slew_rate_max / fabsf(_pid_info.slew_rate);
        // ... apply scaling ...
    }
}
```

This **Dynamic Gain Reduction** is a sophisticated way to handle vibration. Instead of just clipping the output (which causes instability), it temporarily "softens" the drone until the vibration spike passes.

## Tuning & Behavior
*   **Default Value:** 0.0 (Disabled)
*   **Range:** 0 - 200
*   **Effect of Increasing:** Snappier, more immediate roll authority.
*   **Effect of Decreasing:** Smoother motor response, longer motor/ESC life.

### Use Case Recommendations
*   **Standard build:** **Keep at 0.0.** Modern DShot ESCs and rigid frames generally handle raw commands well.
*   **Large Heavy Lift (>15 inch props):** **Set to 50 - 100.** High rotating mass makes instant speed changes impossible; the slew limit prevents the ESCs from wasting energy and heat trying to fight physics.
*   **Commercial VTOL:** **Set to 30.** Comfort and reliability are more important than razor-sharp FPV handling.

### Troubleshooting
*   **Scenario:** Motors make a high-pitched "chirp" or "screech" during fast maneuvers or in wind.
    *   **Diagnosis:** High-frequency PID transients are exceeding the ESC's ability to sync.
    *   **Fix:** Set `ATC_RAT_RLL_SMAX` to 100.