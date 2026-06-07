---
layout: parameter
name: Q_TAILSIT_DSKLD
display_name: Tailsitter Disk Loading
description: The estimated disk loading (in kg/m^2) of the tailsitter rotors.
default_value: 0
range: 0 100
units: kg/m^2
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Disk Loading (Q_TAILSIT_DSKLD)

## Description
`Q_TAILSIT_DSKLD` provides a physical reference for the aerodynamic forces on the rotors. 

Disk loading is the weight of the drone divided by the total area of the spinning props. High disk loading (small props on heavy drone) means high-speed propwash, which requires different control surface gains than low disk loading.