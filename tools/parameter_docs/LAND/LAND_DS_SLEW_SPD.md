---
layout: parameter
name: LAND_DS_SLEW_SPD
display_name: Deepstall Slew Speed
description: The time (in seconds) it takes to move the elevator from normal flight position to full deep-stall deflection.
default_value: 0.5
range: 0 2
units: s
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L69
---

# Deepstall Slew Speed (LAND_DS_SLEW_SPD)

## Description
`LAND_DS_SLEW_SPD` controls how fast the plane "pops up" into the stall.

*   **Fast (0.1s):** Violent entry. Good for precise spot landing but high stress on the airframe.
*   **Slow (1.0s):** Gentle entry. The plane will balloon up before falling.

## Tuning & Behavior
*   **Default Value:** 0.5 s.
*   **Recommendation:** Adjust to get a clean break into the stall without zooming up too high.
