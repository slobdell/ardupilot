---
layout: parameter
name: TMODE_VMIN
display_name: Toy Mode Min Voltage Threshold
description: The battery voltage (per cell) at which thrust scaling is disabled.
default_value: 3.5
range: 3.0 4.2
units: V
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/toy_mode.cpp#L126
---

# Toy Mode Min Voltage Threshold (TMODE_VMIN)

## Description
`TMODE_VMIN` sets the "Floor" for battery compensation in Toy Mode. 

When the battery voltage drops to this level, the autopilot applies the maximum scaling set in [TMODE_TMAX](TMODE_TMAX.html). This is calibrated for single-cell (1S) voltages, as Toy Mode is primarily used on small consumer drones.

## Tuning & Behavior
*   **Default:** 3.5V.
*   **Physics:** Defines the $X_1$ point in a linear interpolation for thrust scaling.