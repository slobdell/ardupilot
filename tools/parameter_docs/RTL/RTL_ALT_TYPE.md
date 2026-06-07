---
layout: parameter
name: RTL_ALT_TYPE
display_name: RTL Altitude Type
description: Controls the altitude reference used for Return to Launch.
default_value: 0
range: 0 1
units: 
group: RTL
visual_asset_id: rtl_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L946
---

# RTL Altitude Type (RTL_ALT_TYPE)

## Description
`RTL_ALT_TYPE` enables Terrain Following during RTL.

*   **0 (Default):** Relative to Home. The drone flies at `RTL_ALT` above the takeoff point.
*   **1:** Terrain. The drone flies at `RTL_ALT` above the ground beneath it (requires a Rangefinder or Terrain Database).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use **1** if you are flying in hilly terrain to ensure the drone climbs over ridges on its way home.