---
layout: parameter
name: DSPOILR_RUD_RATE
display_name: Differential spoilers rudder rate
description: Sets the amount of deflection that the rudder output will apply to the differential spoilers, as a percentage.
default_value: 100
range: -100 100
units: %
group: DSPOILR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Differential spoilers rudder rate (DSPOILR_RUD_RATE)

## Description
Defines the authority of the rudder stick over the differential spoilers. When set to 100%, full rudder input results in full spoiler deflection on one side to aid in yaw.