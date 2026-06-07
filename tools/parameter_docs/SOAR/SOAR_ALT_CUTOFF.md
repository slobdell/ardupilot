---
layout: parameter
name: SOAR_ALT_CUTOFF
display_name: Soaring Cutoff Altitude
description: The altitude (relative to home) at which the motor is automatically turned off to begin a glide.
default_value: 250.0
range: 0 5000.0
units: m
group: SOAR
visual_asset_id: soaring_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L113
---

# Soaring Cutoff Altitude (SOAR_ALT_CUTOFF)

## Description
`SOAR_ALT_CUTOFF` defines the "Start of Mission" altitude for autonomous gliders.

When the drone is climbing using its motor, it will continue until it hits this altitude. At that point, ArduSoar kills the motor and begins the search for lift.

## Tuning & Behavior
*   **Default Value:** 250.0 meters.
*   **Recommendation:** Set high enough to ensure you find lift, but low enough to save battery for multiple climb cycles.