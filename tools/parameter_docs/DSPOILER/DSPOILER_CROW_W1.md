---
layout: parameter
name: DSPOILER_CROW_W1
display_name: Crow outer flap weight
description: The amount of flap output (as a percentage) that is mixed into the outer differential spoilers for crow flaps.
default_value: 0
range: 0 100
units: %
group: DSPOILER
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Crow outer flap weight (DSPOILER_CROW_W1)

## Description
Defines the scaling factor for the "Crow" brake effect (flaps down, spoilers up) on the outer pair of differential spoilers.