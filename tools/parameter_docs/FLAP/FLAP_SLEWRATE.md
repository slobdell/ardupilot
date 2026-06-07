---
layout: parameter
name: FLAP_SLEWRATE
display_name: Flap Slew Rate
description: The percentage per second that the flaps can change by.
default_value: 75
range: 0 100
units: %/s
group: FLAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Flap Slew Rate (FLAP_SLEWRATE)

## Description
Limits how quickly the flaps move from one position to another. This prevents sudden changes in lift and pitch when the flaps are deployed or retracted.