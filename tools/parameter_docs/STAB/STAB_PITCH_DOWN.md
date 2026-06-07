---
layout: parameter
name: STAB_PITCH_DOWN
display_name: "Low throttle pitch down trim"
description: "Degrees of down pitch added when throttle is low"
default_value: 2.0f
range: 0 15
units: "deg"
group: STAB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L89
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Low throttle pitch down trim (STAB_PITCH_DOWN)

## Description
This parameter improves flight safety in stabilized modes (like FBWA) by automatically pitching the nose down when the pilot reduces the throttle. This mimics the natural behavior of a well-trimmed aircraft and helps maintain airspeed during glides or landing approaches, preventing accidental stalls.

## The Mathematics
$$ \text{Pitch}_{\text{bias}} = \text{STAB\_PITCH\_DOWN} \times \frac{\text{TRIM\_THROTTLE} - \text{Throttle}_{\text{in}}}{\text{TRIM\_THROTTLE} - \text{THR\_MIN}} $$
*(Applied only when Throttle < TRIM_THROTTLE)*

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`. This bias is added to the pitch controller's setpoint.

## Tuning & Behavior
*   **Default Value:** 2.0 degrees
*   **Increase:** If the aircraft floats too much or slows down dangerously when you cut the throttle.
*   **Decrease:** If the nose drops too aggressively.