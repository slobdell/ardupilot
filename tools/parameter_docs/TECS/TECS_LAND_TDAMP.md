---
layout: parameter
name: TECS_LAND_TDAMP
display_name: Landing Throttle Damping
description: Specialized damping gain for the throttle controller during the landing phase.
default_value: 0
range: 0 1.0
units: 
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TECS/AP_TECS.cpp#L213
---

# Landing Throttle Damping (TECS_LAND_TDAMP)

## Description
`TECS_LAND_TDAMP` allows for more aggressive throttle corrections during an autonomous landing.

During an approach, the plane must stay precisely on the glide slope while maintaining airspeed. If the throttle response is too slow, the plane might fall behind the power curve. This parameter allows you to add damping (which actually increases throttle activity to counteract speed/height errors) specifically for the landing phase.

*   **0 (Default):** Uses the standard [TECS_THR_DAMP](TECS_THR_DAMP.html) value.
*   **Non-Zero:** Overrides the standard damping with this value.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** If your plane's airspeed varies wildly during the approach, or if it struggles to stay on the glide slope in wind, try setting this to **0.5**. 
*   **Effect:** Higher values result in more frequent and faster throttle movements to maintain the energy state.