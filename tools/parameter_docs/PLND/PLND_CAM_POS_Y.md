---
layout: parameter
name: PLND_CAM_POS_Y
display_name: Camera Y Position Offset
description: The right/left distance (in meters) of the landing camera relative to the drone's center of gravity.
default_value: 0
range: -5 5
units: m
group: PLND
visual_asset_id: cam_offset_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L85
---

# Camera Y Position Offset (PLND_CAM_POS_Y)

## Description
`PLND_CAM_POS_Y` defines the lateral offset of the landing sensor.

*   **Positive Y:** Camera is to the right of center.
*   **Negative Y:** Camera is to the left of center.

See [PLND_CAM_POS_X](PLND_CAM_POS_X.html) for detailed explanation.
