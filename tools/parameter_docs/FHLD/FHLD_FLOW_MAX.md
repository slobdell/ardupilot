---
layout: parameter
name: FHLD_FLOW_MAX
display_name: FlowHold Flow Rate Max
description: Controls the maximum apparent flow rate allowed in FlowHold mode to prevent oscillation.
default_value: 0.6
range: 0.1 2.5
units: 
group: FHLD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold Flow Rate Max (FHLD_FLOW_MAX)

## Description
A safety limit on the optical flow input. This prevents the controller from reacting too aggressively to high flow rates, which can occur when flying very close to the ground.