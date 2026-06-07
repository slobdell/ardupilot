---
layout: parameter
name: LAND_FLAP_PERCNT
display_name: Landing Flap Percentage
description: The percentage of flap deployment during the landing stage.
default_value: 0
range: 0 100
units: %
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Landing Flap Percentage (LAND_FLAP_PERCNT)

## Description
`LAND_FLAP_PERCNT` sets the flap position for the final approach.

*   **0:** Use the standard `FLAP_1_PERCENT` or automatic flap logic.
*   **1-100:** Override with a specific landing setting (e.g. Full Flaps).

## Tuning & Behavior
*   **Default Value:** 0.