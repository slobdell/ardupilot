---
layout: parameter
name: SOAR_ALT_MAX
display_name: Maximum Soaring Altitude
description: The maximum altitude (relative to home) at which the drone will continue to thermal.
default_value: 350.0
range: 0 5000.0
units: m
group: SOAR
visual_asset_id: soaring_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L99
---

# Maximum Soaring Altitude (SOAR_ALT_MAX)

## Description
`SOAR_ALT_MAX` is the "Ceiling" for thermal hunting.

When the drone is circling in a thermal and reaches this altitude, it will automatically exit the circle and return to its mission. This is used for both legal compliance (staying below 400ft/120m) and performance (avoiding thin air where glide performance drops).

## Tuning & Behavior
*   **Default Value:** 350.0 meters.
*   **Recommendation:** Set to your local legal altitude limit.