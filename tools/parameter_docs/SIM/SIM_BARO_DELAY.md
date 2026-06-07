---
layout: parameter
name: SIM_BARO_DELAY
display_name: Simulated Barometer Delay
description: The delay (in milliseconds) added to simulated barometer data.
default_value: 0
range: 0 1000
units: ms
group: SIM
visual_asset_id: sim_lag_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L202
---

# Simulated Barometer Delay (SIM_BARO_DELAY)

## Description
`SIM_BARO_DELAY` adds lag to the altitude reading. High lag can cause the drone to "bounce" in AltHold because the controller is reacting to where the drone *was*, not where it *is*.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Use to test controller stability.