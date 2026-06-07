---
layout: parameter
name: FENCE_MARGIN
display_name: Fence Margin
description: Distance that the autopilot should maintain from the fence to avoid a breach.
default_value: 2.0
range: 1 10
units: m
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence Margin (FENCE_MARGIN)

## Description
A buffer zone inside the fence boundary. The flight controller will attempt to turn the vehicle back once it enters this margin, rather than waiting for the hard boundary of the fence itself.