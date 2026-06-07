---
layout: parameter
name: MOT_THST_HOVER
display_name: Thrust Hover Value
description: The estimated throttle percentage required to maintain a stable hover.
default_value: 0.35
range: 0.125 0.6875
units: 
group: MOT
visual_asset_id: mot_thst_hover_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L138
---

# Thrust Hover Value (MOT_THST_HOVER)

## Description
`MOT_THST_HOVER` stores the throttle level (0.0 to 1.0) required to keep the drone stationary in the air.

This value is the foundation for the entire altitude controller. The autopilot assumes that `MOT_THST_HOVER` provides exactly 1G of lift. The PIDs then calculate adjustments *relative* to this baseline.

## The Mathematics
$$ \text{Throttle Output} = \text{MOT\_THST\_HOVER} + \text{PID}( \text{Altitude Error} ) $$

If this value is too low, the P-term has to work constantly to add thrust, causing the drone to sag when entering AltHold.
If too high, the drone jumps up when entering AltHold.

## The Engineer's View
Used in `AP_MotorsMulticopter::set_throttle_hover()`.
Typically updated automatically if `MOT_HOVER_LEARN` is 2.
Range is clamped between `MOT_SPIN_MIN` and `MOT_SPIN_MAX`.

## Tuning & Behavior
*   **Default Value:** 0.35 (35%)
*   **Range:** 0.125 - 0.6875
*   **Recommendation:**
    *   **Let it learn:** Set `MOT_HOVER_LEARN = 2`, fly in Loiter for 30 seconds, land, disarm. This value will update itself.
    *   **Manual Setting:** Hover in Stabilize mode. Note the throttle stick position (e.g., 40%). Set `MOT_THST_HOVER` to 0.40.
    *   **Optimal Range:** A well-designed multicopter hovers between **0.25 and 0.50**. If hovering > 0.65, the drone is underpowered. If hovering < 0.15, it is overpowered (and will be hard to land).