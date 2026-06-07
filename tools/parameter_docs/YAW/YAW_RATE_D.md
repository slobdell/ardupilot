---
layout: parameter
name: YAW_RATE_D
display_name: Yaw Rate D Gain
description: The derivative gain for the yaw rate controller. Dampens the yaw response.
default_value: 0
range: 0 0.05
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L102
---

# Yaw Rate D Gain (YAW_RATE_D)

## Description
`YAW_RATE_D` acts as a brake for horizontal rotation.

It is rarely needed for multirotors, as the drag of the propellers usually provides enough natural damping. However, on large drones with heavy batteries mounted far from the center, a small amount of D-gain can help stop the rotation more cleanly.
