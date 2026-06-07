---
layout: parameter
name: YAW_RATE_I
display_name: Yaw Rate I Gain
description: The integral gain for the yaw rate controller. Corrects for long-term heading drift.
default_value: 0.02
range: 0 0.1
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L101
---

# Yaw Rate I Gain (YAW_RATE_I)

## Description
`YAW_RATE_I` ensures the drone stays pointed in the correct direction over long periods.

If the drone is constantly being pushed by a crosswind or has an imbalanced motor, the I-term builds up pressure to hold the nose exactly where it is supposed to be.
