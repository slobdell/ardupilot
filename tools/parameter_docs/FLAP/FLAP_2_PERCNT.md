---
layout: parameter
name: FLAP_2_PERCNT
display_name: Automatic Flap Percentage (Stage 2)
description: The amount of flap deflection (in percent) applied when the aircraft drops below the second (lower) speed threshold.
default_value: 0
range: 0 100
units: %
group: FLAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L712
---

# Automatic Flap Percentage (Stage 2) (FLAP_2_PERCNT)

## Description
`FLAP_2_PERCNT` defines the "Full Flaps" or secondary deployment stage.

When the plane slows down even further (below [FLAP_2_SPEED](FLAP_2_SPEED.html)), the autopilot will increase the flap deflection to this value.