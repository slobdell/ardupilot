---
layout: parameter
name: ATC_RAT_YAW_SMAX
display_name: Yaw Axis Rate Slew Rate Limit
description: Limits the maximum rate of change of the motor output requested by the yaw rate controller. Prevents high-frequency motor oscillations and protects ESCs from extreme current spikes during heading changes.
default_value: 0.0
range: 0 200
units: 
group: ATC
visual_asset_id: atc_rat_yaw_smax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L67
---

# Yaw Axis Rate Slew Rate Limit (ATC_RAT_YAW_SMAX)

## Description
`ATC_RAT_YAW_SMAX` is a protective mechanism for your drone's torsional stability. A **Slew Rate** is a limit on how fast a command signal can change over time. 

In the yaw controller, if the PID loop calculates that it needs to jump from 10% motor torque to 90% motor torque instantly (due to a violent gust or a sensor spike), the ESCs and motors will experience a massive, potentially destructive surge in current. This parameter rounds off those spikes, ensuring that the motor command always increases or decreases at a rate your hardware can safely handle.

*   **Low Value:** Yaw response feels extremely smooth and "damped." Motors will sound very quiet.
*   **High Value:** Allows the yaw authority to reach its target power as fast as possible.
*   **Too High:** Risk of "motor chirping" or ESC failure due to extreme current transients during fast yaw turns.
*   **Disabled (0):** The software does not limit the rate of change of the yaw motor command.

## The Mathematics
The slew limit acts as a "speed limit" for the change in the yaw motor command ($O_{yaw}$):

$$ |O_{new} - O_{prev}| \leq SMAX \cdot dt $$

If the calculated change in output exceeds $SMAX$, ArduPilot automatically reduces the P and D gains of the yaw rate loop for that specific cycle to keep the command within the limit:

$$ \text{Gain Scale Factor} = \frac{SMAX}{\text{Calculated Change}} $$

## The Engineer's View
This parameter maps to `_slew_rate_max` in the `_pid_rate_yaw` object.

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

This **Dynamic Gain Reduction** is especially useful for preventing "Yaw Jumps" at the end of high-speed maneuvers, where aerodynamic forces can cause large momentary rate errors.

## Tuning & Behavior
*   **Default Value:** 0.0 (Disabled)
*   **Range:** 0 - 200
*   **Effect of Increasing:** Snappier, more immediate yaw authority. Essential for high-speed tracking.
*   **Effect of Decreasing:** Smoother motor response, longer motor/ESC life.

### Use Case Recommendations
*   **Large Prop Drones (>18 inch):** **Set to 50 - 80.** Large arms have low torsional rigidity; limiting the slew rate prevents the arms from "twisting" and vibrating.
*   **Industrial VTOL:** **Set to 40.** Heading precision is less important than reliability and mechanical longevity.
*   **FPV Freestyle:** **Keep at 0.0.** Pilots generally prefer the absolute minimum latency in their yaw response.

### Troubleshooting
*   **Scenario:** Drone's tail makes a "snap" or "pop" sound during sharp turns.
    *   **Diagnosis:** High-frequency yaw transients are exceeding the frame's torsional rigidity.
    *   **Fix:** Set `ATC_RAT_YAW_SMAX` to 100.