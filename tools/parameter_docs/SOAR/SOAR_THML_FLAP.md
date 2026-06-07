---
layout: parameter
name: SOAR_THML_FLAP
display_name: Soaring Thermal Flap Setting
description: The specific flap percentage to be used while circling in a thermal.
default_value: 0
range: 0 100
units: %
group: SOAR
visual_asset_id: sailboat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Soaring/AP_Soaring.cpp#L165
---

# Soaring Thermal Flap Setting (SOAR_THML_FLAP)

## Description
`SOAR_THML_FLAP` defines the specialized wing configuration used for maximum lift during the "Thermalling" phase.

When a glider is circling in a thermal, it typically flies at a much lower speed than during cross-country cruise. Deploying a specific amount of flap increases the wing's camber, providing more lift and allowing the plane to circle tightly and slowly without stalling. This parameter overrides the usual flight mode flap settings specifically for soaring.

## Tuning & Behavior
*   **Default:** 0%.
*   **Recommendation:** Set this to the "Thermal" or "Launch" flap position recommended by your glider's manufacturer (typically **10% to 30%**).
*   **Significance:** Higher flap settings improve the "Climb" efficiency but increase drag, which is fine while you are inside the lifting air of a thermal.