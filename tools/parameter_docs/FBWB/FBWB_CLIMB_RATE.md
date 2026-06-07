---
layout: parameter
name: FBWB_CLIMB_RATE
display_name: FBWB Climb Rate
description: Maximum climb or descent rate in m/s for FBWB and CRUISE modes (Plane).
default_value: 2
range: 0.1 20
units: m/s
group: FBWB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# FBWB Climb Rate (FBWB_CLIMB_RATE)

## Description
Defines the maximum vertical speed achievable when the elevator stick is fully deflected in Fly-By-Wire B (FBWB) or CRUISE modes.