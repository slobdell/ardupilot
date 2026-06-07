---
layout: parameter
name: ZIGZ_SPRAYER
display_name: ZigZag Mode Auto Sprayer
description: Enables automatic sprayer control based on mission progress in ZigZag mode.
default_value: 0
range: 0 1
units: 
group: ZIGZ
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_zigzag.cpp#L64
---

# ZigZag Mode Auto Sprayer (ZIGZ_SPRAYER)

## Description
`ZIGZ_SPRAYER` automates the crop-spraying process.

When enabled, the autopilot will automatically turn on the sprayer (via a relay or PWM) as the drone begins a "Zig" or "Zag" leg, and turn it off when it reaches the end point or while it is performing a lateral step. This ensures that chemicals are only applied over the intended area and not wasted during turns.