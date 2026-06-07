---
layout: parameter
name: NAVL1_XTRACK_I
display_name: L1 Cross-Track Integrator
description: Integral gain to eliminate persistent cross-track error (off-path distance).
default_value: 0.02
range: 0 1.0
units: 
group: NAVL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_L1_Control/AP_L1_Control.cpp#L32
---

# L1 Cross-Track Integrator (NAVL1_XTRACK_I)

## Description
`NAVL1_XTRACK_I` corrects for "Crabbing" caused by wind.

If there is a strong crosswind, a plane might fly parallel to the path but a few meters to one side. This Integrator term slowly builds up over time to force the plane back onto the exact center of the line.