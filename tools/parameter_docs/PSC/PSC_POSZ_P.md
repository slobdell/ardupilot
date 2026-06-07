---
layout: parameter
name: PSC_POSZ_P
display_name: Position Control (Vertical) P Gain
description: Converts the altitude error (target - current) into a desired climb or descent rate.
default_value: 1.0
range: 1.0 3.0
units: 
group: PSC
visual_asset_id: psc_posz_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L121
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_P_1D.cpp#L11
---

# Position Control (Vertical) P Gain (PSC_POSZ_P)

## Description
The `PSC_POSZ_P` parameter controls the "springiness" of the drone's altitude hold. It defines how aggressively the drone attempts to correct its height when it notices it is above or below its target altitude.

*   **Low Value:** The drone will feel "lazy" vertically. If you push it down, it will drift back up very slowly. It may sag when flying forward at speed.
*   **High Value:** The drone fights hard to maintain its altitude. It reacts instantly to small changes in height.
*   **Too High:** The drone will start to bounce or oscillate vertically (up and down) as it over-corrects small pressure sensor errors.

## The Mathematics
This parameter is the Proportional ($k_P$) term in the outer Altitude loop.

$$ V_{z\_target} = k_P \cdot (Z_{target} - Z_{current}) $$

Where:
*   $V_{z\_target}$ is the requested climb/descent rate (in cm/s) passed to the inner Velocity Loop.
*   $Z_{target}$ is the desired altitude (Barometer or Rangefinder).
*   $Z_{current}$ is the EKF estimated altitude.
*   $k_P$ is `PSC_POSZ_P`.
*   **Dimensionality:** Since it converts Altitude ($L$) to Velocity ($L T^{-1}$), the unit of $k_P$ is $1/s$ (Hertz).

**Example:** If the drone is 1 meter (100cm) below its target and `PSC_POSZ_P` is 1.0, it will command a 100 cm/s climb rate. If you increase it to 2.0, it will command 200 cm/s for the same error.

## The Engineer's View
This parameter is an instance of `AC_P_1D` (member `_p_pos_z`) within `AC_PosControl`.

It is executed in `AC_PosControl::update_z_controller()`:

```cpp
// AC_PosControl.cpp
_vel_target.z = _p_pos_z.update_all(pos_target_zf, _inav.get_position_z_up_cm());
```

The climb rate output is then capped by `PILOT_SPEED_UP` and `PILOT_SPEED_DN` before being sent to the Velocity PID loop.

## Tuning & Behavior
*   **Default Value:** 1.0 (Standard)
*   **Range:** 1.0 - 3.0
*   **Effect of Increasing:** Faster return to target altitude. "Locked-in" feel.
*   **Effect of Decreasing:** Smoother altitude transitions. More forgiving of sensor noise (Baro drift).

### Use Case Recommendations
*   **Cinematography:** **Keep Default (1.0).** Standard 1.0 provides a natural, smooth altitude hold that isn't robotic or jerky.
*   **Terrain Following (Low Altitude):** **Increase to 1.5 - 2.0.** When flying close to the ground using a rangefinder, you want the drone to follow the contours of the earth precisely. A higher P-gain ensures it doesn't "crash" into a hill because it was too slow to climb.
*   **Heavy Lift / Tethered:** **Decrease to 0.8.** Reduces the chance of vertical oscillations if the drone is physically constrained by a cable or heavy payload.

### Troubleshooting
*   **Scenario:** Drone "bounces" up and down slowly in Loiter.
    *   **Diagnosis:** `PSC_POSZ_P` is too high, creating a resonant oscillation with the landing throttle.
    *   **Fix:** Reduce `PSC_POSZ_P` in steps of 0.2.
