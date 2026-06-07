---
layout: parameter
name: TECS_LAND_PDAMP
display_name: Landing Pitch Damping
description: Specialized damping gain for the pitch controller during the landing phase.
default_value: 0
range: 0 1.0
units: 
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TECS/AP_TECS.cpp#L237
---

# Landing Pitch Damping (TECS_LAND_PDAMP)

## Description
`TECS_LAND_PDAMP` allows for a more "Solid" pitch response during the critical landing approach.

Landing often happens in ground effect or turbulent air near the runway, which can cause the plane's nose to bounce or oscillate. This parameter allows you to add extra damping specifically for the landing phase without affecting the feel of the aircraft during normal cruise.

*   **0 (Default):** Uses the standard [TECS_PTCH_DAMP](TECS_PTCH_DAMP.html) value.
*   **Non-Zero:** Overrides the standard damping with this value.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** If your plane "Pitch pumps" (constantly moves the nose up and down) while on the landing glide slope, set this to **0.5** or **0.8**.
*   **Effect:** Higher values make the pitch response more sluggish but significantly more stable against external disturbances.