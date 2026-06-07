---
layout: parameter
name: TMODE_TMAX
display_name: Toy Mode Max Thrust Multiplier
description: The thrust scaling factor applied when the battery voltage is at its lowest.
default_value: 1.0
range: 0.1 1.0
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/toy_mode.cpp#L150
---

# Toy Mode Max Thrust Multiplier (TMODE_TMAX)

## Description
`TMODE_TMAX` is the low-voltage counterpart to `TMIN`. It defines the scaling factor applied when the battery is near empty.

Typically, this is kept at **1.0** (full available power) to compensate for the naturally lower voltage of a drained battery.

## Tuning & Behavior
*   **Default:** 1.0.
*   **Physics:** As voltage drops, RPM drops. By setting `TMIN` < 1.0 and `TMAX` = 1.0, the autopilot "unlocks" more signal range as the battery drains to maintain constant lift.