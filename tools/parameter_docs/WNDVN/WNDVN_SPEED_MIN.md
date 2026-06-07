---
layout: parameter
name: WNDVN_SPEED_MIN
display_name: Wind Vane Cut-off Speed
description: Minimum wind speed required for the wind vane data to be trusted.
default_value: 0
range: 0 5
units: m/s
group: WNDVN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L114
---

# Wind Vane Cut-off Speed (WNDVN_SPEED_MIN)

## Description
`WNDVN_SPEED_MIN` prevents the autopilot from reacting to "Flutter" or "Dithering" when there is no wind. 

Physical wind vanes require a certain amount of airflow to overcome friction and point accurately. In very light winds, a vane might just flop around or stay stuck in an old position. This parameter tells the autopilot to ignore the wind direction data unless the measured wind speed is above this threshold.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Set to **0.5 m/s** to **1.0 m/s** depending on how free-moving your physical wind vane is. 
*   **Dependencies:** Requires a functional wind speed sensor ([WNDVN_SPEED_TYPE](WNDVN_SPEED_TYPE.html)).