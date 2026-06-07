---
layout: parameter
name: PSC_VELXY_IMAX
display_name: Position Control Velocity (XY) I-Term Maximum
description: The maximum limit for the horizontal velocity integrator. Limits how much the drone can "lean" to compensate for steady-state errors like strong wind.
default_value: 1000
range: 0 4500
units: cm/s/s
group: PSC
visual_asset_id: psc_velxy_imax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L1066
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_2D.cpp#L32
---

# Position Control Velocity (XY) I-Term Maximum (PSC_VELXY_IMAX)

## Description
`PSC_VELXY_IMAX` defines the maximum "tilt authority" given to the velocity integrator (`PSC_VELXY_I`). 

The integrator's primary job is to fight constant wind. If a 20-knot wind is pushing your drone, the integrator builds up a permanent lean into the wind to hold position. This parameter prevents that lean from becoming too extreme. It ensures that even if the drone is struggling against a hurricane, the software won't command a tilt so steep that the drone loses lift and falls out of the sky.

*   **Low Value:** Limits the drone's ability to hold position in strong winds.
*   **High Value:** Allows the drone to lean very steeply to fight wind, but increases the risk of "windup" (where the drone stays tilted for several seconds after the wind stops).
*   **Default (1000):** Equivalent to 1000 cm/s² (about 10% of gravity), or roughly 6 degrees of "I-term lean."

## The Mathematics
The velocity integrator ($\vec{I}$) is clamped by this value in the XY plane:

$$ \text{Length}(\vec{I}_{new}) = \text{constrain}(\text{Length}(\vec{I}_{prev} + \vec{V}_{err} \cdot k_I \cdot dt), 0, \text{IMAX}) $$

Where:
*   $\text{IMAX}$ is `PSC_VELXY_IMAX`.
*   The output is a 2D vector (North/East), so the *magnitude* of the vector is capped.

## The Engineer's View
This parameter maps to `_kimax` in the `_pid_vel_xy` object.

It is applied in `AC_PID_2D::update_i()`:

```cpp
// AC_PID_2D.cpp
_integrator += delta_integrator;
_integrator.limit_length(_kimax);
```

Note that `AC_PID_2D` uses a circular (vector) limit, which is mathematically superior to capping North and East independently, as it prevents the drone from having more authority on the diagonals.

## Tuning & Behavior
*   **Default Value:** 1000 (10.0 m/s² authority)
*   **Range:** 0 - 4500 (0 to 45 m/s² authority)
*   **Effect of Increasing:** Better position holding in extreme wind.
*   **Effect of Decreasing:** Safer flight in gusty conditions; reduces the chance of the drone "darting" after a windup.

### Use Case Recommendations
*   **Extreme High-Wind Ops (Offshore):** **Increase to 2000.** This allows for about 12 degrees of permanent tilt to fight sustained ocean winds.
*   **Precision Indoor Mapping:** **Decrease to 500.** Indoors there is no wind; a lower IMAX prevents the integrator from learning "fake" offsets from sensor drift.
*   **Racing / Acro:** **Keep Default.** Standard values are usually sufficient as racers rely more on P-gain than I-term authority.

### Troubleshooting
*   **Scenario:** Drone is holding position against wind, but when the wind stops, the drone "shoots" forward for a few meters before leveling out.
    *   **Diagnosis:** Integrator Windup. `PSC_VELXY_IMAX` is too high, allowing too much "memory" to build up.
    *   **Fix:** Reduce `PSC_VELXY_IMAX` to 800 or 500.

