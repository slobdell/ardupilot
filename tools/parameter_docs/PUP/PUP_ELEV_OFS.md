---
layout: parameter
name: PUP_ELEV_OFS
display_name: Elevator deflection used before starting pullup
description: Elevator deflection offset from -1 to 1 while waiting for airspeed to rise before starting close loop control of the pullup.
default_value: 0
range: -1.0 1.0
units: %
group: PUP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/pullup.cpp#L23
---

# PUP_ELEV_OFS: Elevator deflection used before starting pullup

## Description
Elevator deflection offset from -1 to 1 while waiting for airspeed to rise before starting close loop control of the pullup.

## Values
- **Range:** -1.0 to 1.0
- **Units:** % (Normalized)
- **Default:** 0

## Description
This parameter applies a fixed elevator offset during the "Freefall" phase.

- **Function:** While the aircraft is diving to gain speed (before the high-G pull-up begins), this offset is applied to the elevator.
- **Usage:** Typically set to 0. Can be used to trim the aircraft for a specific dive angle if it has a tendency to pitch up or down naturally.

