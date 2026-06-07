---
layout: parameter
name: SOAR_POLAR_K
display_name: Wing Loading Factor (K)
description: A factor representing the wing loading of the aircraft.
default_value: 25.6
range: 20 400
units: m²/s²
group: SOAR
visual_asset_id: glider_polar_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L92
---

# Wing Loading Factor (SOAR_POLAR_K)

## Description
`SOAR_POLAR_K` accounts for the weight and wing area of your glider.

It acts as the "Scaling Constant" for the entire drag polar. A heavy glider needs to fly faster to stay in the air, and this parameter tells the math model exactly how much faster.

## The Mathematics
$$ K = \frac{2 \cdot m \cdot g}{\rho \cdot S} $$

Where:
*   $m$ is mass (kg).
*   $g$ is gravity (9.81).
*   $ho$ is air density (~1.225 at sea level).
*   $S$ is wing area ($m^2$).

## Tuning & Behavior
*   **Default Value:** 25.6.
*   **Recommendation:** If you add a larger battery (making the plane heavier), you must increase `K` proportionally to maintain accuracy.