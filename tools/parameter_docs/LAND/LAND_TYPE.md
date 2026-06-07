---
layout: parameter
name: LAND_TYPE
display_name: Default Landing Type
description: The landing type to use when no specific type is requested (0=Standard, 1=DeepStall).
default_value: 0
range: 0 1
units: 
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Default Landing Type (LAND_TYPE)

## Description
`LAND_TYPE` sets the default behavior for the `LAND` flight mode.

*   **0:** Standard fixed-wing landing (Glide slope -> Flare).
*   **1:** Deep Stall landing (Pop up -> Vertical descent).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Deep Stall:** Requires `LAND_DS_*` parameters to be configured first.