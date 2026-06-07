---
layout: parameter
name: RTL_ALT_FINAL
display_name: RTL Final Altitude
description: The altitude (in centimeters) the vehicle will descend to after returning to the home location.
default_value: 0
range: 0 1000
units: cm
group: RTL
visual_asset_id: rtl_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L946
---

# RTL Final Altitude (RTL_ALT_FINAL)

## Description
`RTL_ALT_FINAL` determines what the drone does after it arrives home.

*   **0 (Default):** Land immediately.
*   **> 0:** Hover at this altitude.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use **0** for automated safety. Use **200 (2m)** if you want the drone to come home and wait for you to catch it or manually land it.
