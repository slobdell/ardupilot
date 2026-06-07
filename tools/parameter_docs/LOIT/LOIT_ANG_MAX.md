---
layout: parameter
name: LOIT_ANG_MAX
display_name: Loiter Maximum Lean Angle
description: Limits the maximum lean angle (roll and pitch) the drone can use while in Loiter mode. If set to 0, it defaults to the global ANGLE_MAX.
default_value: 0
range: 0 45
units: deg
group: LOIT
visual_asset_id: loit_ang_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L28
---

# Loiter Maximum Lean Angle (LOIT_ANG_MAX)

## Description
`LOIT_ANG_MAX` is the "tilt limiter" specifically for Loiter mode. 

When you fly in **Loiter**, the flight controller is doing two things at once: following your stick commands and fighting the wind. If both of these require a steep lean, the drone might tilt too far and lose altitude. `LOIT_ANG_MAX` allows you to cap the "aggression" of Loiter mode, making it gentler and safer than manual flight modes like **Stabilize**. 

*   **Set to 0 (Default):** The drone uses the global `ANGLE_MAX` (typically 30-45 degrees).
*   **Set > 0:** The drone will never lean further than this angle in Loiter, even if you push the sticks to the limit and a strong wind is blowing.

**Physical Meaning:** A lower lean angle means a lower maximum speed and slower braking. If you set this to 15 degrees, the drone will feel very calm and stable, but it won't be able to fly fast.

## The Mathematics
The controller uses a ternary selector to determine the active limit ($\theta_{limit}$):

$$ \theta_{limit} = \begin{cases} \text{LOIT_ANG_MAX}, & \text{if } \text{LOIT_ANG_MAX} > 0 \\ \text{ANGLE_MAX}, & \text{otherwise} \end{cases} $$

Where $\theta_{limit}$ is in degrees. This limit is applied to the final output of the 2D position and velocity controllers before the lean angle is sent to the attitude controller.

## The Engineer's View
This parameter is the `_angle_max` member in `AC_Loiter`.

It is applied at the end of the `AC_Loiter::update()` cycle. One important technical detail is that **this limit includes wind compensation**. If the wind requires 10 degrees of tilt to hold position, and `LOIT_ANG_MAX` is set to 20 degrees, the pilot only has 10 degrees of "leftover" tilt to use for movement. This ensures the drone never exceeds its safety envelope.

## Tuning & Behavior
*   **Default Value:** 0 (Inherit Global)
*   **Range:** 0 - 45 degrees
*   **Effect of Increasing:** Allows the drone to fly faster and stop more aggressively in Loiter mode.
*   **Effect of Decreasing:** Makes the drone feel much more stable and predictable. Safe for beginners.

### Use Case Recommendations
*   **Aerial Cinematography:** **Set to 20.** Ensures the drone never tilts so aggressively that it jerks the gimbal or brings the propellers into the camera's view.
*   **Underpowered Drones / Large Payload:** **Set to 25.** Prevents the drone from leaning so far that it doesn't have enough vertical thrust to stay in the air.
*   **Standard build:** **Keep at 0.** Let the global safety limits handle the drone's behavior.

### Troubleshooting
*   **Scenario:** My drone hovers perfectly, but it's incredibly slow in Loiter mode, even with `LOIT_SPEED` set to 2000.
    *   **Diagnosis:** `LOIT_ANG_MAX` is set too low, preventing the drone from tilting far enough to reach the target speed.
    *   **Fix:** Set `LOIT_ANG_MAX` to 0 or increase to 30.