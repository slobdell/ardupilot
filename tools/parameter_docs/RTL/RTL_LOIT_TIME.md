---
layout: parameter
name: RTL_LOIT_TIME
display_name: RTL Loiter Time
description: The time (in milliseconds) the vehicle will hover above the home point before starting its final descent.
default_value: 5000
range: 0 60000
units: ms
group: RTL
visual_asset_id: rtl_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L946
---

# RTL Loiter Time (RTL_LOIT_TIME)

## Description
`RTL_LOIT_TIME` gives you a chance to take control.

When the drone arrives overhead, it will pause for this duration. This is your opportunity to switch modes if you want to land manually.

## Tuning & Behavior
*   **Default Value:** 5000 ms (5 seconds).
*   **Recommendation:** Keep at least **5000**.
