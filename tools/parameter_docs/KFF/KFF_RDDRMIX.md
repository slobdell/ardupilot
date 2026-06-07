---
layout: parameter
name: KFF_RDDRMIX
display_name: Rudder to Aileron Mix
description: The amount of rudder deflection to apply automatically when rolling the aircraft.
default_value: 0.5
range: 0 1.0
units: 
group: KFF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Rudder to Aileron Mix (KFF_RDDRMIX)

## Description
`KFF_RDDRMIX` automates "Coordinated Turns" for airplanes.

When a plane rolls into a turn using ailerons, it often experiences "Adverse Yaw" (the tail swinging the wrong way). This parameter automatically adds a proportional amount of rudder to keep the nose pointed into the wind during the roll.