---
layout: parameter
name: DSPOILER_AILMTCH
display_name: Crow flap aileron matching
description: Percentage of aileron input that is mixed into the crow flap differential spoiler output.
default_value: 100
range: 0 100
units: %
group: DSPOILER
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Crow flap aileron matching (DSPOILER_AILMTCH)

## Description
Determines how much the spoilers continue to act as ailerons while the Crow braking is active. 100% means they maintain full roll authority.