---
layout: parameter
name: SOAR_THML_BANK
display_name: Thermalling Bank Angle
description: The bank angle (in degrees) the glider uses when circling inside a thermal.
default_value: 30.0
range: 20 50
units: deg
group: SOAR
visual_asset_id: soaring_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L125
---

# Thermalling Bank Angle (SOAR_THML_BANK)

## Description
`SOAR_THML_BANK` determines the "Tightness" of your search circle.

To stay inside a narrow thermal, the glider must bank its wings.
*   **Shallow Bank (20°):** Large circles. Good for wide, weak thermals, but easy to fall out of a small one.
*   **Steep Bank (45°):** Tight circles. Good for centering on small, strong thermals, but increases the "Induced Drag," which makes the plane sink faster.

## Tuning & Behavior
*   **Default Value:** 30.0°.
*   **Recommendation:** 30° to 35° is a good sweet spot for most foam gliders.