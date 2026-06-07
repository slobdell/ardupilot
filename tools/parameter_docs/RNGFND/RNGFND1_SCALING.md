---
layout: parameter
name: RNGFND1_SCALING
display_name: Rangefinder Scaling
description: Scaling factor for analog rangefinders (Meters per Volt).
default_value: 3.0
range: 0 100
units: m/V
group: RNGFND
visual_asset_id: rngfnd_scaling_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L35
---

# Rangefinder Scaling (RNGFND1_SCALING)

## Description
`RNGFND1_SCALING` calibrates **Analog** rangefinders (Type 1). It defines how many meters of distance correspond to 1.0 Volt of output.

$$ \text{Distance} = (\text{Voltage} \times \text{Scaling}) + \text{Offset} $$

*   **Example:** If 1V = 1m, set Scaling to 1.0.
*   **Example:** Maxbotix EZ4 outputs ~3.3V at 7m. Scaling ≈ 2.12.

## Tuning & Behavior
*   **Default:** 3.0
*   **Calculation:** Measure the voltage at a known distance. $Scaling = \frac{\text{Distance}}{\text{Voltage}}$.