---
layout: parameter
name: ATC_RAT_RLL_D_FF
display_name: Roll Axis Rate Derivative Feed-Forward
description: Derivative feed-forward gain for the roll rate loop. Provides pre-emptive motor correction based on how quickly the roll command is changing.
default_value: 0.0
range: 0 0.02
units: 
group: ATC
visual_asset_id: atc_rat_rll_d_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L81
---

# Roll Axis Rate Derivative Feed-Forward (ATC_RAT_RLL_D_FF)

## Description
`ATC_RAT_RLL_D_FF` is an advanced "predictive" term for roll control. While standard Feed-Forward (`ATC_RAT_RLL_FF`) looks at the target rotation speed, the **Derivative Feed-Forward (D_FF)** looks at how fast you are *moving the stick*.

Think of it as the "pre-acceleration" boost. If you slam the roll stick to the side, you are requesting a sudden jump in rotation speed. The D_FF term "senses" this rapid movement and instantly adds a massive burst of motor power to overcome the inertia of the propellers *before* the drone even starts to roll. It allows the drone to "lead" into a maneuver with zero lag.

*   **Low Value (0.0):** Standard behavior. The drone accelerates as fast as its P-gain and base FF allow.
*   **High Value:** Creates a very aggressive "snap" at the start of every roll.
*   **Too High:** Can cause the motors to "bark" or click, and potentially lead to over-snapping where the drone overshoots the initial rotation.

## The Mathematics
The D_FF term is proportional to the derivative of the target rotation rate ($\\omega_{target}$):

$$ \text{Out}_{D\_FF} = \frac{d(\\omega_{target})}{dt} \cdot k_{D\_FF} $$

Where:
*   $k_{D\_FF}$ is `ATC_RAT_RLL_D_FF`.
*   $\\frac{d(\\omega_{target})}{dt}$ is the rate of change of your stick input (in deg/s²).

This is added to the total motor demand alongside the standard P, I, D, and FF terms.

## The Engineer's View
This parameter maps to `_kdff` in the `_pid_rate_roll` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float target_derivative = (target - _last_target) / dt;
    _pid_info.D_FF = target_derivative * _kdff;
}
```

Because it looks at the **Target** (software) rather than the **Gyro** (sensor), D_FF is immune to motor vibration noise. This makes it a much safer way to get "crisp" response than simply cranking up the standard D-gain.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0.0 - 0.02
*   **Effect of Increasing:** Snappier, more instantaneous roll response. Reduces the "initial sag" at the start of a flip.
*   **Effect of Decreasing:** Smoother, more natural-feeling rotations.

### Use Case Recommendations
*   **FPV Racing / Freestyle:** **Increase to 0.005 - 0.01.** Essential for the "robotic" and instant feel required to navigate tight technical courses.
*   **Standard GPS Flying:** **Keep at 0.0.** The standard shaper and P-gain are sufficient for smooth flight.
*   **High-Speed Tracking:** **Increase to 0.003.** Helps the drone follow rapid movements of a subject without falling behind the "lead."

### Troubleshooting
*   **Scenario:** Drone makes a loud "pop" or "snap" sound from the motors every time you move the stick.
    *   **Diagnosis:** `ATC_RAT_RLL_D_FF` is too high.
    *   **Fix:** Reduce to 0.0 or 0.002.