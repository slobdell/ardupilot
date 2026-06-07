---
layout: parameter
name: YAW_RATE_P
display_name: Yaw Rate P Gain
description: The proportional gain for the yaw rate controller.
default_value: 0.25
range: 0.1 0.5
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L100
---

# Yaw Rate P Gain (YAW_RATE_P)

## Description
`YAW_RATE_P` controls how aggressively the drone stops its horizontal rotation.

When you let go of the yaw stick, the drone should stop spinning and hold its new heading. If the drone is slow to stop or "Drifts" around, you need more P.

*   **Too High:** The tail will "Wag" or vibrate horizontally.
*   **Too Low:** The drone will be slow to respond to yaw commands and will not hold its heading well in the wind.
