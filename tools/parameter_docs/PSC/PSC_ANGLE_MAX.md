--- 
layout: parameter
name: PSC_ANGLE_MAX
display_name: Position Control Angle Max
description: Limits the maximum lean angle the autopilot can request while in Position Control modes (Loiter, Auto, Guided). If set to 0, it defaults to the global ANGLE_MAX.
default_value: 0
range: 0 4500
units: cdeg
group: PSC
visual_asset_id: psc_angle_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L1233
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.h#L519
---

<!-- 
  NOTE: This file is a manually investigated Golden Sample based on Source Code Truth.
-->

# Position Control Angle Max (PSC_ANGLE_MAX)

## Description
The `PSC_ANGLE_MAX` parameter serves as a safety governor for autonomous flight. It strictly limits how far the drone can tilt (lean) when it is flying itself (Loiter, Auto, Guided, RTL).

By default (`0`), it inherits the global `ANGLE_MAX` setting (typically 30-45 degrees), which applies to manual flight (Stabilize/AltHold). However, you often want autonomous modes to be gentler than manual modes. This parameter allows you to cap the auto-flight tilt to a lower value (e.g., 20 degrees) for smoother video or passenger comfort, while keeping the full range available for manual recovery.

*   **Set to 0:** Disabled. Uses `ANGLE_MAX`.
*   **Set > 0:** Overrides `ANGLE_MAX` for Position Control modes.

## The Mathematics
The logic uses a ternary selector:

$$ \theta_{limit} = \begin{cases} \text{PSC\_ANGLE\_MAX}, & \text{if } \text{PSC\_ANGLE\_MAX} > 0 \\ \text{ANGLE\_MAX}, & \text{otherwise} \end{cases} $$

Where $\theta_{limit}$ is the maximum centi-degrees of roll or pitch allowed.

## The Engineer's View
This parameter corresponds to `_lean_angle_max` in `AC_PosControl`.

The logic is explicitly defined in `AC_PosControl::get_lean_angle_max_cd()`:

```cpp
// AC_PosControl.cpp
float AC_PosControl::get_lean_angle_max_cd() const
{
    if (is_positive(_angle_max_override_cd)) {
        return _angle_max_override_cd;
    }
    if (!is_positive(_lean_angle_max)) {
        return _attitude_control.lean_angle_max_cd(); // Returns global ANGLE_MAX
    }
    return _lean_angle_max * 100.0f;
}
```

This limit is applied at the very end of the `update_xy_controller()` loop to clip the requested acceleration.

## Tuning & Behavior
*   **Default Value:** 0 (Inherit Global)
*   **Range:** 0 - 4500 (0 to 45 degrees)
*   **Effect of Increasing:** Allows the drone to fly faster in Auto/Loiter (since speed comes from tilt).
*   **Effect of Decreasing:** Limits top speed and acceleration. Makes flight smoother but reduces wind resistance.

### Use Case Recommendations
*   **Cinematography:** **Set to 1500 - 2000 (15-20 deg).**
    *   *Why:* Ensures the drone never tilts aggressively, keeping the landing gear out of the shot and the horizon stable.
*   **High Wind Operations:** **Set to 0 (or >3000).**
    *   *Why:* If you cap this too low (e.g., 10 degrees) and the wind requires a 12-degree lean to hold position, the drone will be blown away (Fly-away risk).
*   **General:** **Keep Default (0).**