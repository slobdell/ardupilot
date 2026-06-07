---
layout: parameter
name: SOAR_THML_ARSPD
display_name: Soaring Thermal Airspeed
description: The airspeed (in m/s) the glider uses when circling inside a thermal.
default_value: 0
range: 0 50
units: m/s
group: SOAR
visual_asset_id: glider_polar_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L129
---

# Soaring Thermal Airspeed (SOAR_THML_ARSPD)

## Description
`SOAR_THML_ARSPD` is the "Best Glide" speed for circling.

When you are inside a thermal, you want to stay in the air as long as possible (minimum sink rate).

*   **0 (Default):** Use `AIRSPEED_CRUISE`.
*   **Value:** Hold this specific speed.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to your plane's "Minimum Sink Speed" (usually slightly slower than your best glide speed).