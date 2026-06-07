---
layout: parameter
name: ATC_ANGLE_BOOST
display_name: Angle Boost
description: Automatically increases the throttle as the drone tilts (leans) to compensate for the loss of vertical lift. Prevents the drone from losing altitude when flying forward.
default_value: 1
range: 0 1
units: 
group: ATC
visual_asset_id: atc_angle_boost_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L49
---

# Angle Boost (ATC_ANGLE_BOOST)

## Description
`ATC_ANGLE_BOOST` is the "Auto-Altitude" feature of ArduPilot. 

When a drone tilts to move forward, some of its propeller force is redirected sideways. Because less force is now pointing straight down, the drone will naturally lose altitude and "sink" unless the pilot increases the throttle. `ATC_ANGLE_BOOST` automates this. It "boosts" the throttle command based on how steep the lean is, ensuring the drone maintains a consistent hover height whether it's sitting still or zooming forward.

*   **Enabled (1):** The drone stays at the same height automatically during turns and forward dashes.
*   **Disabled (0):** The drone will sink whenever it tilts. The pilot must manually manage altitude with the throttle stick.

## The Mathematics
The boost factor is based on the trigonometry of the drone's tilt angle ($\theta$):

$$ \text{Throttle}_{boosted} = \frac{\text{Throttle}_{base}}{\cos(\theta)} $$

Where:
*   $\theta$ is the combined roll and pitch angle.
*   $\cos(\theta)$ represents the vertical component of the total thrust vector.

**Example:** If a drone tilts by 60 degrees, its vertical lift is cut in half ($\cos(60^\circ) = 0.5$). To stay level, it must **double** its total motor power. `ATC_ANGLE_BOOST` handles this math instantly.

## The Engineer's View
This parameter is the `_angle_boost_enabled` member in `AC_AttitudeControl`.

It is applied in `AC_AttitudeControl_Multi::get_throttle_boosted()`:

```cpp
// AC_AttitudeControl_Multi.cpp
float cos_tilt = _ahrs.cos_pitch() * _ahrs.cos_roll();
float boost_factor = 1.0f / constrain_float(cos_tilt_target, 0.1f, 1.0f);
float throttle_out = throttle_in * inverted_factor * boost_factor;
```

Crucially, the code includes a **Tilt-Limit Safeguard**: As the drone approaches 90 degrees (vertical), the math would command "infinite" power. ArduPilot caps the boost factor to prevent motor saturation and ensures the drone maintains enough control authority to level itself out.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Range:** 0 (Off) or 1 (On)
*   **Effect of Enabling:** Much easier to fly in manual modes. Essential for AltHold and Loiter to work correctly.
*   **Effect of Disabling:** "Old school" flight feel. The drone will descend during any movement.

### Use Case Recommendations
*   **Standard Multirotor:** **Always Keep Enabled (1).** There is almost no reason to turn this off for modern multirotor flight.
*   **Acrobatic Training:** **Disable (0) occasionally.** If you want to learn how full-sized helicopters fly (where you must manually coordinate throttle and cyclic), turning this off provides a realistic challenge.
*   **Cinematography:** **Always Keep Enabled (1).** Ensures perfectly level tracking shots.

### Troubleshooting
*   **Scenario:** Drone "climbs" slightly every time I fly forward at speed.
    *   **Diagnosis:** This is rare, but usually means your motor thrust is non-linear or you have extreme aerodynamic lift from the drone's body.
    *   **Fix:** Check `MOT_THST_EXPO`. If the problem persists, you can't "tune" angle boost (it's binary), so look for mechanical or sensor issues.