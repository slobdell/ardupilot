---
layout: parameter
name: ATC_RAT_PIT_SMAX
display_name: Pitch Axis Rate Slew Rate Limit
description: Limits the maximum rate of change of the motor output requested by the pitch rate controller. Prevents high-frequency motor oscillations and protects ESCs from extreme current spikes during pitch maneuvers.
default_value: 0.0
range: 0 200
units: 
group: ATC
visual_asset_id: atc_rat_pit_smax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L67
---

# Pitch Axis Rate Slew Rate Limit (ATC_RAT_PIT_SMAX)

## Description
`ATC_RAT_PIT_SMAX` is a protection mechanism for your drone's longitudinal stability. A **Slew Rate** is a limit on how fast a command signal can change over time. 

In the pitch controller, if the PID loop calculates that it needs to jump from 20% motor power to 80% motor power instantly (due to a violent gust or a sensor spike), the ESCs and motors will experience a massive, potentially destructive surge in current. This parameter rounds off those spikes, ensuring that the motor command always increases or decreases at a rate your hardware can safely handle.

*   **Low Value:** Pitch response feels extremely smooth and "damped." Motors will sound very quiet.
*   **High Value:** Allows the pitch motors to reach their target power as fast as they physically can.
*   **Too High:** Risk of "motor chirping" or ESC failure due to extreme current transients during fast pitch changes.
*   **Disabled (0):** The software does not limit the rate of change of the pitch motor command.

## The Mathematics
The slew limit acts as a "speed limit" for the change in the pitch motor command ($O_{pit}$):

$$ |O_{new} - O_{prev}| \leq SMAX \cdot dt $$

If the calculated change in output exceeds $SMAX$, ArduPilot automatically reduces the P and D gains of the pitch rate loop for that specific cycle to keep the command within the limit:

$$ \text{Gain Scale Factor} = \frac{SMAX}{\text{Calculated Change}} $$

## The Engineer's View
This parameter maps to `_slew_rate_max` in the `_pid_rate_pitch` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(_slew_rate_max)) {
    _pid_info.slew_rate = (P + D - _last_out_pd) / dt;
    if (fabsf(_pid_info.slew_rate) > _slew_rate_max) {
        // Dynamically lower authority for this loop cycle to prevent mechanical shock
        float scale = _slew_rate_max / fabsf(_pid_info.slew_rate);
        // ... apply scaling ...
    }
}
```

This **Dynamic Gain Reduction** allows the drone to remain stable while protecting the hardware from high-frequency resonant "shocks" that could otherwise break motor mounts or frames.

## Tuning & Behavior
*   **Default Value:** 0.0 (Disabled)
*   **Range:** 0 - 200
*   **Effect of Increasing:** Sharper, more immediate pitch authority. Essential for high-speed tracking.
*   **Effect of Decreasing:** Smoother motor response, longer motor/ESC life, and quieter overall flight.

### Use Case Recommendations
*   **Large Prop Professional Drones (>18 inch):** **Set to 50 - 80.** High rotating inertia makes instant speed changes impossible; the slew limit prevents wasted energy and heat.
*   **Industrial VTOL:** **Set to 40.** Reliability and mechanical longevity are prioritized over razor-sharp freestyle handling.
*   **FPV Freestyle:** **Keep at 0.0.** Pilots generally prefer the absolute minimum latency in their pitch response.

### Troubleshooting
*   **Scenario:** Drone makes a high-pitched "scratching" sound during vertical punches or sharp stops.
    *   **Diagnosis:** High-frequency pitch transients are exceeding the frame's rigidity or the ESC's update capability.
    *   **Fix:** Set `ATC_RAT_PIT_SMAX` to 100 and re-test.