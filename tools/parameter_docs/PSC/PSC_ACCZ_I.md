---
layout: parameter
name: PSC_ACCZ_I
display_name: Position Control Acceleration (Vertical) I Gain
description: Integral gain for the vertical acceleration loop. Primarily used to "learn" the vehicle's hover throttle and compensate for battery voltage sag or payload changes.
default_value: 1.0
range: 0.0 3.0
units: 
group: PSC
visual_asset_id: psc_accz_i_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L18
---

# Position Control Acceleration (Vertical) I Gain (PSC_ACCZ_I)

## Description
`PSC_ACCZ_I` is the "gravity memory" of the drone. It works in the innermost vertical loop to ensure that the drone actually generates the required lift to stay level. 

Its most important role is compensating for **Hover Throttle**. If you add a heavy camera to your drone, it now requires 60% throttle to hover instead of 50%. The I-term "notices" the persistent downward acceleration error and increases the baseline throttle until the drone stops sinking.

*   **Low Value:** The drone will sink significantly when you first switch to AltHold or Loiter. It may also sink during the end of a battery's life as voltage drops.
*   **High Value:** The drone adapts quickly to changes in weight or voltage.
*   **Too High:** The drone will "bounce" or "hunt" for the hover point, creating a slow vertical surge.

## The Mathematics
This parameter scales the accumulation of vertical acceleration error.

$$ \text{Throttle}_{out} += \int_0^t (\vec{A}_{z\_target} - \vec{A}_{z\_measured}) \cdot k_I \cdot dt $$

Where:
*   $\vec{A}_{z\_target} - \vec{A}_{z\_measured}$ is the instantaneous error in vertical force.
*   $k_I$ is `PSC_ACCZ_I`.
*   **Dimensionality:** This gain converts Acceleration-Time into Throttle.

**Anti-Windup:** ArduPilot heavily limits the maximum value of this integrator via `PSC_ACCZ_IMAX` to ensure the drone doesn't full-throttle itself into space if it's held down on a table.

## The Engineer's View
This parameter is the `_ki` member of the `_pid_accel_z` object inside `AC_PosControl`.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_integrator += (_error * _ki) * dt;
```

A unique feature in ArduPilot is that this I-term is often **pre-seeded** (initialised) with the known `MOT_THST_HOVER` value during take-off to prevent the drone from "dropping" when it first transitions into an autonomous vertical mode.

## Tuning & Behavior
*   **Default Value:** 1.0
*   **Range:** 0.0 - 3.0
*   **Effect of Increasing:** Faster adaptation to weight changes. More consistent hover height as the battery drains. 
*   **Effect of Decreasing:** Smoother vertical behavior, but the drone will "sag" more under load.

### Use Case Recommendations
*   **Standard Build:** **Keep Default (1.0).** This is robust for almost all vehicles.
*   **Heavy Lift / Cargo (Variable Weight):** **Increase to 1.5.** If you are dropping a payload, you want the drone to instantly "learn" its new lighter weight and not rocket upwards.
*   **Low Power-to-Weight (Underpowered):** **Decrease to 0.5.** Prevents the integrator from pushing the motors into saturation too quickly.

### Troubleshooting
*   **Scenario:** Drone sinks for 2-3 seconds every time you switch to Loiter, then slowly climbs back to the right height.
    *   **Diagnosis:** `PSC_ACCZ_I` is too low. It's taking too long to "learn" the gravity offset.
    *   **Fix:** Increase `PSC_ACCZ_I` by 0.5.

