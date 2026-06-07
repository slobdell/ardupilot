---
layout: parameter
name: PSC_ACCZ_SMAX
display_name: Position Control Acceleration (Vertical) Slew Rate Limit
description: Limits the maximum rate of change of the motor output requested by the vertical PID loop. Prevents high-frequency motor oscillations and reduces mechanical stress.
default_value: 0.0
range: 0 200
units: 
group: PSC
visual_asset_id: psc_accz_smax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L67
---

# Position Control Acceleration (Vertical) Slew Rate Limit (PSC_ACCZ_SMAX)

## Description
`PSC_ACCZ_SMAX` is a protection mechanism for your motors and frame. A **Slew Rate** is a limit on how fast a signal can change over time. 

If the vertical acceleration loop commands 10% throttle now and 90% throttle in the very next millisecond (due to noise or a sudden correction), the motors will try to accelerate violently. This causes massive current spikes and can actually shake the drone's frame apart. This parameter rounds off those sudden spikes, ensuring that the motor command always changes at a physically safe rate.

*   **Low Value:** Flight feels extremely soft and "buttery." The motors will sound very quiet.
*   **High Value:** Allows the motors to reach their target power as fast as they physically can.
*   **Too High:** Risk of "motor shrieking" and ESC damage due to extreme current transients.
*   **Disabled (0):** The software does not limit the rate of change of the motor command.

## The Mathematics
The slew limit acts as a "speed limit" for the change in the PID output ($\Delta O$):

$$ |O_{new} - O_{prev}| \leq SMAX \cdot dt $$

If the calculated change in output exceeds $SMAX$, ArduPilot automatically reduces the P and D gains of the acceleration loop for that specific cycle to keep the output within the limit:

$$ \text{Scale Factor} = \frac{SMAX}{|P + D|_{rate}} $$

## The Engineer's View
This parameter maps to `_slew_rate_max` in the `_pid_accel_z` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(_slew_rate_max)) {
    _pid_info.slew_rate = (P + D - _last_out_pd) / dt;
    if (fabsf(_pid_info.slew_rate) > _slew_rate_max) {
        // Reduce gains to meet the slew rate
        float gain_reduction = _slew_rate_max / fabsf(_pid_info.slew_rate);
        // ... apply reduction ...
    }
}
```

This is a **dynamic gain reduction** strategy. Instead of just clipping the output (which creates lag), it softens the controller until the "jerkiness" is gone.

## Tuning & Behavior
*   **Default Value:** 0.0 (Disabled)
*   **Range:** 0 - 200
*   **Effect of Increasing:** Snappier, more immediate vertical control authority.
*   **Effect of Decreasing:** Smoother motor response, longer motor life, and potentially less "jello" in the camera feed.

### Use Case Recommendations
*   **Standard Build:** **Keep at 0.0.** Modern ESCs and frames are usually strong enough to handle raw PID output.
*   **Large Professional Drones (>10kg):** **Set to 50 - 100.** Large drones have massive rotating inertia; trying to change their motor speed instantly is inefficient and stresses the ESCs.
*   **Passenger-Carrying / Large VTOL:** **Set to 20.** Safety and comfort are paramount; violent motor changes must be prevented by the software.

### Troubleshooting
*   **Scenario:** Motors are making a "crunchy" or "scratchy" sound during fast descents.
    *   **Diagnosis:** High-frequency PID chatter is creating excessive slew rates.
    *   **Fix:** Set `PSC_ACCZ_SMAX` to 100 and check if the sound cleans up.
