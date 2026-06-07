---
layout: parameter
name: MAN_EXPO_RUDDER
display_name: "Manual input expo for rudder"
description: "Percentage exponential for rudder input in MANUAL, ACRO and TRAINING modes"
default_value: 0
range: 0 100
units: "%"
group: MAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1261
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.h#L577
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Manual input expo for rudder (MAN_EXPO_RUDDER)

## Description
This parameter adds **Exponential** (Expo) to the Rudder stick input when flying in Manual, Acro, or Training modes. Expo softens the response around the center of the stick, allowing for precise small corrections, while maintaining full control authority at the stick limits.

## The Mathematics
$$ \text{Input}_{shaped} = (1 - k) \cdot \text{Input} + k \cdot \text{Input}^3 $$
Where $ k = \frac{\text{MAN\_EXPO\_RUDDER}}{100} $.

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`. Used in `Plane::read_radio()` to pre-process the RC input before it is passed to the servo mixers. This applies only to the Rudder channel.

## Tuning & Behavior
*   **Default Value:** 0% (Linear response)
*   **Range:** 0 - 100%
*   **30-40%:** Typical value for smoother yaw control.
*   **Higher Values:** Very soft center, aggressive endpoint response.