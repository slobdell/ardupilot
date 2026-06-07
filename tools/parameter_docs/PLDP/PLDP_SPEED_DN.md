---
layout: parameter
name: PLDP_SPEED_DN
display_name: Payload-Place Descent Speed
description: The descent rate (in cm/s) used during the final package placement phase.
default_value: 50
range: 10 500
units: cm/s
group: PLDP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Payload-Place Descent Speed (PLDP_SPEED_DN)

## Description
`PLDP_SPEED_DN` sets the vertical speed of the drone as it lowers the package to the ground.