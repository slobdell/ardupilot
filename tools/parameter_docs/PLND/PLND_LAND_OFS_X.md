---
layout: parameter
name: PLND_LAND_OFS_X
display_name: "Land offset forward"
description: "Desired landing position of the camera forward of the target in vehicle body frame."
default_value: 0
range: -20 20
units: "cm"
group: PLND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L63
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Land offset forward (PLND_LAND_OFS_X)

## Description
This parameter allows you to intentionally "offset" the final touchdown position of the vehicle along its forward/back (X) axis. While precision landing usually aims to put the camera directly over the center of the target, you might want the vehicle to land slightly forward or back from that center point.

This is particularly useful if your landing gear requires a specific alignment on a platform or if you want to avoid landing directly on top of a physical beacon.

## The Mathematics
The offset is applied as a static translation in the vehicle's body-frame before being rotated into the global navigation frame.

$$ \text{Pos}_{target\_final} = \text{Pos}_{target\_detected} + \text{Rotation}_{BodyToNED}(\text{LAND\_OFS\_X}, \text{LAND\_OFS\_Y}, 0) $$

A **positive** value shifts the landing point **forward** (the vehicle will land with the camera ahead of the target). A **negative** value shifts it **backward**.

## The Engineer's View
In `AC_PrecLand::run_output_prediction()` (`libraries/AC_PrecLand/AC_PrecLand.cpp`), the `_land_ofs_cm_x` and `_land_ofs_cm_y` values are converted to meters and added to the relative target position estimate.
This translation is performed *after* the camera's physical position offset (`CAM_POS`) has been accounted for, ensuring that `LAND_OFS` is purely a bias on the final desired landing spot.

## Tuning & Behavior
*   **Default Value:** 0 cm.
*   **Range:** -20 to 20 cm.
*   **Tuning:** If your drone consistently lands 5cm too far back from the center of the pad, set this to **5** to shift the landing point forward.
*   **Note:** This is an intentional bias. If the vehicle is missing the target due to wind or poor tuning, do not use this parameter to "fix" it; instead, tune the position controller or L1 parameters.

