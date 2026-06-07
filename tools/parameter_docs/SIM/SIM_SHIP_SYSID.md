---
layout: parameter
name: SIM_SHIP_SYSID
display_name: Simulated Ship System ID
description: The MAVLink System ID broadcast by the simulated ship.
default_value: 0
range: 0 255
units: 
group: SIM
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Ship.cpp#L25
---

# Simulated Ship System ID (SIM_SHIP_SYSID)

## Description
`SIM_SHIP_SYSID` gives the ship a "Voice."

If set to a non-zero value (e.g. 20), the ship will broadcast its position via MAVLink `GLOBAL_POSITION_INT` messages on the simulated network. This allows the drone to track the ship as a dynamic "Follow Me" target or a moving home point.

## Tuning & Behavior
*   **Default Value:** 0 (Silent).