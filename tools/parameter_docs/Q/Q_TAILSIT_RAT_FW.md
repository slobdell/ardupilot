---
layout: parameter
name: Q_TAILSIT_RAT_FW
display_name: Tailsitter FW Rate
description: The maximum pitch rate (in degrees per second) used during the fixed-wing phase of a tailsitter transition.
default_value: 0
range: 0 100
units: deg/s
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter FW Rate (Q_TAILSIT_RAT_FW)

## Description
`Q_TAILSIT_RAT_FW` defines the "Snap" into forward flight.

Once the plane has leaned over enough to gain lift from the wings, this parameter sets how fast it performs the final rotation into the horizontal level position.