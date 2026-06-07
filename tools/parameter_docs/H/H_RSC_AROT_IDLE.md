---
layout: parameter
name: H_RSC_AROT_IDLE
display_name: Autorotation Idle Throttle
description: The throttle percentage (0-40%) sent to the motor during an active autorotation.
default_value: 0
range: 0 40
units: %
group: H
visual_asset_id: heli_rsc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Autorotation/RSC_Autorotation.cpp#L37
---

# Autorotation Idle Throttle (H_RSC_AROT_IDLE)

## Description
`H_RSC_AROT_IDLE` keeps the motor "Spinning but not Engaging" during an autorotation.

This is primarily for combustion engines or electric ESCs with a "bailout window." It ensures the engine doesn't drop to a true idle or stop completely, allowing for a much faster re-engagement of power if needed.
