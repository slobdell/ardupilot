---
layout: parameter
name: NET_PASS1_OPT2
display_name: Network Passthrough 1 Options 2
description: Configuration options for the second endpoint of the network serial passthrough channel.
default_value: 0
range: 0 255
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_port.cpp#L100
---

# Network Passthrough 1 Options 2 (NET_PASS1_OPT2)

## Description
`NET_PASS1_OPT2` enables specific features for the second side of the bridge.