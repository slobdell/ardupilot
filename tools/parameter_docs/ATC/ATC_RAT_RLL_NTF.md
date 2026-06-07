---
layout: parameter
name: ATC_RAT_RLL_NTF
display_name: Roll Axis Rate Target Notch Filter Index
description: Selects which Harmonic Notch Filter instance (1-8) should be applied to the roll rate setpoint. Cleans up resonances in the commanded rotation speed.
default_value: 0
range: 1 8
units: 
group: ATC
visual_asset_id: atc_rat_rll_ntf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L89
---

# Roll Axis Rate Target Notch Filter Index (ATC_RAT_RLL_NTF)

## Description
`ATC_RAT_RLL_NTF` is the sister filter to the "Error Notch" filter. While the error notch cleans up noise from the **Sensors** (IMU), the target notch cleans up noise from the **Commands** (Software).

In a complex multi-layered control system, the "target rate" (how fast you want to roll) is the result of many calculations—GPS position planners, obstacle avoidance systems, and mission planners. Sometimes, these software processes can introduce rhythmic "ripples" or high-frequency pulses into the command. If these pulses happen to match the physical resonance of your drone's frame, they can cause the drone to vibrate or sound "grainy." 

This parameter allows the flight controller to surgically remove those command-side frequencies before they ever reach the motors.

*   **Set to 0:** No notch filter is applied to the roll target rate.
*   **Set to 1-8:** Uses the corresponding Harmonic Notch filter (configured via `INS_HNTCH_*`).

## The Mathematics
The notch filter ($H_{notch}$) is applied to the target rate signal ($\omega_{target}$) at the very beginning of the PID calculation:

$$ \omega_{target\_clean} = H_{notch}( \omega_{target\_raw} ) $$

The clean target $\omega_{target\_clean}$ is then used for the error calculation and the Feed-Forward path. 

## The Engineer's View
This parameter maps to `_notch_T_filter` in the `_pid_rate_roll` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (_notch_T_filter > 0) {
    // Passes the target through the INS library's harmonic notch pointer
    target = _notch_T_filter_ptr->apply(target);
}
```

This is rarely needed on standard multirotors, but is an essential tool for **Heavy Lift** or **Experimental** frames where software path-planning jitter can excite mechanical arm resonances.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 1 - 8 (Filter Index)
*   **Effect of Enabling:** Smoother motor sound during rapid maneuvers. Eliminates rhythmic vibrations caused by high-level software setpoints.
*   **Effect of Disabling:** Maximum responsiveness to command changes.

### Use Case Recommendations
*   **Standard Multirotor:** **Keep at 0.** ArduPilot's standard input shapers provide plenty of smoothing for the command signal.
*   **Flexible Wings / Long-Arm Octocopters:** **Consider setting to 1.** Large frames can act like tuning forks; a command-side notch ensures the software never accidentally "plucks" the arm at its resonant frequency.
*   **Precision Surveying (RTK):** **Set to 1.** Very high-precision GPS position loops can sometimes introduce tiny high-frequency corrections that a notch filter can clean up.

### Troubleshooting
*   **Scenario:** Drone makes a faint "ringing" or "humming" sound specifically during Auto missions or Loiter, but is perfectly quiet in manual Stabilize.
    *   **Diagnosis:** Command-side resonance.
    *   **Fix:** Apply a notch filter at the resonant frequency via `ATC_RAT_RLL_NTF`.