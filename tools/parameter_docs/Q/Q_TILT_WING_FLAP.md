---
layout: parameter
name: Q_TILT_WING_FLAP
display_name: Tilt Wing Flap
description: Percentage of flaperon to apply based on tilt angle.
default_value: 0
range: 0 100
units: '%'
group: Q
visual_asset_id: vtol_tilt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tilt Wing Flap (Q_TILT_WING_FLAP)

## Description
`Q_TILT_WING_FLAP` is for **Tilt-Wing** aircraft (where the entire wing rotates, not just the motors).

As the wing tilts up, the ailerons become less effective for roll control. This parameter mixes in some "Flap" to increase lift and control authority during the transition.