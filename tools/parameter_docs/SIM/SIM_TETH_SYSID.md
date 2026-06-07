---
layout: parameter
name: SIM_TETH_SYSID
display_name: Simulated Tether System ID
description: The MAVLink System ID of the tether base station (for reporting tension).
default_value: 0
range: 0 255
units: 
group: SIM
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Tether.cpp#L25
---

# Simulated Tether System ID (SIM_TETH_SYSID)

## Description
`SIM_TETH_SYSID` allows the simulator to spoof messages from a "Smart Tether."

Real tether stations often report cable tension and power usage via MAVLink. This parameter sets the source ID for those simulated messages.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).