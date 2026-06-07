---
layout: parameter
name: ATC_HOVR_ROL_TRM
display_name: Hover Roll Trim
description: Compensation angle to counter the side-force (translation) caused by the tail rotor thrust in a hover.
default_value: 0
range: 0 1000
units: cdeg
group: ATC
visual_asset_id: heli_hover_roll_trim_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Heli.cpp#L17
---

# Hover Roll Trim (ATC_HOVR_ROL_TRM)

## Description
`ATC_HOVR_ROL_TRM` is a helicopter-specific parameter. Traditional helicopters produce a side-force from their tail rotor while hovering. To stay in one spot, the helicopter must lean slightly (Roll) in the opposite direction of the tail thrust.

This parameter allows you to pre-set that lean angle so the autopilot doesn't have to "discover" it via the I-term every time you take off.

*   **Units:** Centi-degrees (100 = 1 degree).
*   **Effect:** Reduces horizontal drift immediately after takeoff in manual modes and improves position-hold performance in autonomous modes.

## The Mathematics
The roll trim $\phi_{trim}$ is added directly to the Euler roll target $\phi_{target}$:
$$ \phi_{final} = \phi_{target} + \phi_{trim} $$

In inverted flight, the sign is automatically flipped by the `inverted_factor`:
$$ \text{inverted_factor} = \text{clamp}(2.0 \cdot \cos(\text{roll}), -1.0, 1.0) $$
$$ \phi_{applied} = \phi_{trim} \cdot \text{inverted_factor} $$

## The Engineer's View
This parameter is the `_hover_roll_trim` member in `AC_AttitudeControl_Heli`.
It is retrieved via `get_roll_trim_rad()` and added to the attitude target in the `input_euler_angle_roll_pitch_euler_rate_yaw` and `input_euler_angle_roll_pitch_yaw` functions.

## Tuning & Behavior
*   **Default Value:** 0 (or board specific)
*   **Range:** 0 to 1000 cdeg (0 to 10 degrees).
*   **Typical Value:** Most helicopters require 3 to 5 degrees (**300 to 500 cdeg**) of roll trim to hover stationary.
*   **Tuning Procedure:**
    1.  Hover in **Stabilize** or **Acro** mode.
    2.  Observe which way the heli drifts horizontally.
    3.  Adjust `ATC_HOVR_ROL_TRM` until the heli stays stationary with the roll stick centered.
    4.  Verify that in **Loiter**, the heli doesn't "lean" excessively or drift when first engaged.