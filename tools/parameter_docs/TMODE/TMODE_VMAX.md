---
layout: parameter
name: TMODE_VMAX
display_name: Toy Mode Max Voltage Threshold
description: The battery voltage (per cell) at which minimum thrust scaling is applied.
default_value: 3.8
range: 3.0 4.2
units: V
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/toy_mode.cpp#L134
---

# Toy Mode Max Voltage Threshold (TMODE_VMAX)

## Description
`TMODE_VMAX` sets the "Ceiling" for battery compensation in Toy Mode. 

When the battery is above this voltage, the autopilot applies the minimum scaling set in [TMODE_TMIN](TMODE_TMIN.html). 

*   **Default:** 3.8V.
*   **Physics:** Defines the $X_2$ point in a linear interpolation for thrust scaling. Between `VMIN` and `VMAX`, the autopilot smoothly varies the motor power to keep the drone's vertical performance constant.