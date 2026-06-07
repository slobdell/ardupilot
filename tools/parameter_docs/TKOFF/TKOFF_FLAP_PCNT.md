---
layout: parameter
name: TKOFF_FLAP_PCNT
display_name: Takeoff Flap Percentage
description: The amount of flaps (0-100%) to automatically deploy during an autonomous takeoff.
default_value: 0
range: 0 100
units: %
group: TKOFF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L220
---

# Takeoff Flap Percentage (TKOFF_FLAP_PCNT)

## Description
`TKOFF_FLAP_PCNT` sets the specialized wing configuration for the "Roll-out" and "Climb-out" phase of an autonomous takeoff.

Deploying flaps increases the wing's lift coefficient, allowing the plane to rotate and become airborne at a lower ground speed. This is essential for short-field takeoffs or for heavy aircraft. 

## Tuning & Behavior
*   **Default:** 0%.
*   **Recommendation:** Set to the "Takeoff Flap" position recommended by your airframe's manufacturer (typically **15% to 40%**).
*   **Automation:** The autopilot will automatically retract the flaps to their normal cruise position once the aircraft reaches a safe altitude and airspeed after takeoff.