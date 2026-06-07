---
layout: parameter
name: TECS_SINK_MAX
display_name: Maximum Descent Rate
description: The maximum vertical speed (in m/s) the autopilot will demand during a descent.
default_value: 5.0
range: 1 15
units: m/s
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L112
---

# Maximum Descent Rate (TECS_SINK_MAX)

## Description
`TECS_SINK_MAX` prevents the drone from diving too steeply.

While gravity is free, diving too fast can lead to structural failure or exceed the plane's "Vne" (Never Exceed Speed). This parameter caps the rate of descent to a safe, controlled speed.
