---
layout: parameter
name: ATC_RAT_YAW_I
display_name: Yaw Axis Rate I Gain
description: Integral gain for the yaw rate controller. Corrects long-term steady-state errors, ensuring the nose of the drone stays perfectly pointed at the target heading.
default_value: 0.018
range: 0.01 1.0
units: 
group: ATC
visual_asset_id: atc_rat_yaw_i_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L18
---

# Yaw Axis Rate I Gain (ATC_RAT_YAW_I)

## Description
`ATC_RAT_YAW_I` is the "heading anchor" for your drone. Its job is to fix persistent rotation errors that the P-gain (`ATC_RAT_YAW_P`) isn't strong enough to stop.

If your drone has motors that aren't perfectly aligned, or if you have a propeller that is slightly damaged, the drone will naturally want to spin (yaw) on its own. The I-term "notices" this constant drift and slowly increases the counter-torque until the rotation stops. It is the parameter that ensures the nose stays exactly where you pointed it, even during long flights or in heavy wind.

*   **Low Value:** The drone will have "Heading Creep." The nose will slowly drift left or right over several minutes. Turn completion will feel vague.
*   **High Value:** Heading is held very strictly. The tail feels "locked."
*   **Too High:** The drone will develop a slow tail oscillation or "hunting" behavior as the tail moves back and forth looking for the target heading.

## The Mathematics
The I-term accumulates the yaw rate error over time:

$$ \text{Out}_I += \int_0^t (\omega_{target} - \omega_{actual}) \cdot k_I \cdot dt $$

Where:
*   $k_I$ is `ATC_RAT_YAW_I`.
*   The result is constrained by `ATC_RAT_YAW_IMAX`.

**Torque Balance:** In multirotors, yaw I-term is essential because any difference in motor performance directly creates a yaw torque. This integrator is the only way the drone can automatically find its internal "zero torque" point.

## The Engineer's View
This parameter is the `_ki` member of the `_pid_rate_yaw` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_integrator += (error * _ki * dt);
_integrator = constrain_float(_integrator, -_kimax, _kimax);
```

ArduPilot's **Yaw Re-centering** logic often resets this integrator when the pilot makes a deliberate large yaw command, allowing the drone to "start fresh" after a big turn without carrying over the old trim authority.

## Tuning & Behavior
*   **Default Value:** 0.018 (Standard)
*   **Range:** 0.01 - 1.0
*   **Effect of Increasing:** Better heading hold, especially at high speed or during vertical "punches."
*   **Effect of Decreasing:** Smoother, more relaxed heading behavior.

### Use Case Recommendations
*   **Cinematography:** **Keep Default or set to 0.015.** You want the heading to be stable, but avoid any sudden "snapping" corrections that the gimbal might not be able to follow.
*   **High Speed Racing:** **Increase to 0.05 - 0.1.** At high speeds, the aerodynamic forces on the drone are massive; a strong I-term is required to keep the nose pointed down the track.
*   **Long-Range Survey:** **Keep Default.** Standard values provide a stable heading for mapping and navigation.

### Troubleshooting
*   **Scenario:** After you finish a turn, the drone's heading continues to "creep" for 5-10 degrees before finally stopping.
    *   **Diagnosis:** `ATC_RAT_YAW_I` is too low.
    *   **Fix:** Increase `ATC_RAT_YAW_I` by 0.005.