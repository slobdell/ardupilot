---
layout: parameter
name: Q_TILT_FIX_GAIN
display_name: Tilt Rotor Fixed Gain
description: The P-gain used to hold the tilt rotors in position when not actively actuating.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_tilt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tilt Rotor Fixed Gain (Q_TILT_FIX_GAIN)

## Description
`Q_TILT_FIX_GAIN` is rarely used but allows for softer holding force when parked.