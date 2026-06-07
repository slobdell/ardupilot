---
layout: parameter
name: H_DCP_YAW
display_name: Direct Cyclic Pitch Yaw
description: Yaw feed-forward compensation based on direct cyclic pitch input.
default_value: 0
range: -1 1
units: 
group: H
visual_asset_id: heli_tail_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L100
---

# Direct Cyclic Pitch Yaw (H_DCP_YAW)

## Description
`H_DCP_YAW` adds a tail kick when you move the cyclic stick.

This is a feed-forward term. If you slam the stick forward, the main rotor torque changes. This parameter tells the tail to compensate instantly, rather than waiting for the gyro to detect a yaw error.