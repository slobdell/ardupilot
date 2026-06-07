---
layout: parameter
name: PLND_LAND_OFS_Y
display_name: "Land offset right"
description: "Desired landing position of the camera right of the target in vehicle body frame."
default_value: 0
range: -20 20
units: "cm"
group: PLND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L72
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Land offset right (PLND_LAND_OFS_Y)

## Description
This parameter allows you to intentionally "offset" the final touchdown position of the vehicle along its left/right (Y) axis. While precision landing usually aims to put the camera directly over the center of the target, you might want the vehicle to land slightly to the right or left of that center point.

This is useful for aligning the drone's landing gear with specific markings on a landing pad or for offset-mounted hardware.

## The Mathematics
The offset is applied as a static translation in the vehicle's body-frame before being rotated into the global navigation frame.

$$ \text{Pos}_{target\_final} = \text{Pos}_{target\_detected} + \text{Rotation}_{BodyToNED}(0, \text{LAND\_OFS\_Y}, 0) $$

A **positive** value shifts the landing point to the **right**. A **negative** value shifts it to the **left**.

## The Engineer's View
In `AC_PrecLand::run_output_prediction()` (`libraries/AC_PrecLand/AC_PrecLand.cpp`), the `_land_ofs_cm_y` value is converted to meters and added to the relative target position estimate.
This translation is performed *after* the camera's physical position offset (`CAM_POS`) has been accounted for, ensuring that `LAND_OFS` is purely a bias on the final desired landing spot.

## Tuning & Behavior
*   **Default Value:** 0 cm.
*   **Range:** -20 to 20 cm.
*   **Tuning:** If your drone consistently lands 5cm to the left of the beacon, set this to **5** (positive) to shift the landing point to the right.
*   **Note:** This is an intentional bias. If the vehicle is missing the target due to wind or poor tuning, do not use this parameter to "fix" it; instead, tune the position controller or L1 parameters.

