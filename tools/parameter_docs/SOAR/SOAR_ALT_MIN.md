---
layout: parameter
name: SOAR_ALT_MIN
display_name: Minimum Soaring Altitude
description: The minimum altitude (relative to home) at which soaring is permitted. Below this altitude, the motor will be used to climb.
default_value: 50.0
range: 0 1000.0
units: m
group: SOAR
visual_asset_id: soaring_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L106
---

# Minimum Soaring Altitude (SOAR_ALT_MIN)

## Description
`SOAR_ALT_MIN` is your "Safety Floor."

If the drone's altitude falls below this limit, ArduSoar stops trying to be clever and just turns on the motor to climb back to safety. This prevents the drone from getting stuck in a weak thermal so low that it can't safely return home.

## Tuning & Behavior
*   **Default Value:** 50.0 meters.
*   **Recommendation:** Set to at least **2x the height of the tallest obstacles** in your area.