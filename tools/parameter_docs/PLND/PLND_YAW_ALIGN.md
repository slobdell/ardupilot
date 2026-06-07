---
layout: parameter
name: PLND_YAW_ALIGN
display_name: Precision Landing Yaw Alignment
description: The rotational offset (in centi-degrees) of the landing sensor relative to the vehicle's forward axis.
default_value: 0
range: 0 36000
units: cdeg
group: PLND
visual_asset_id: cam_offset_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L61
---

# Precision Landing Yaw Alignment (PLND_YAW_ALIGN)

## Description
`PLND_YAW_ALIGN` is used if your landing camera isn't pointing perfectly straight forward.

If you mounted your sensor rotated (e.g., 90 degrees sideways to fit the frame), the "Forward" direction in the camera view would actually be the drone's "Left" direction. This parameter allows you to correct that rotation in software.

*   **Units:** Centi-degrees (100 = 1 degree).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Tuning:** If you command the drone to move "Forward" toward the target, but it moves "Sideways" instead, your alignment is wrong.