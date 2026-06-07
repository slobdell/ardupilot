---
layout: parameter
name: SAIL_HEEL_MAX
display_name: Sail Maximum Heel Angle
description: The maximum allowed tilt (heel) of the boat before the sails are eased.
default_value: 15
range: 0 90
units: deg
group: SAIL
visual_asset_id: sailboat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/sailboat.cpp#L67
---

# Sail Maximum Heel Angle (SAIL_HEEL_MAX)

## Description
`SAIL_HEEL_MAX` is the "Capsize Prevention" setting for autonomous sailboats.

When the boat banks over (heels) due to wind pressure, there is a risk of losing control or taking on water. If the measured heel angle exceeds this value, the autopilot will automatically ease the sails (let the sheet out) to reduce the sideways force and level the boat, even if it means losing speed.

## Tuning & Behavior
*   **Default:** 15 degrees.
*   **Recommendation:** Set this based on your boat's stability. For a wide-beamed boat or one with a heavy keel, you might increase this to **25** or **30** degrees. For a light catamaran, keep it lower (e.g., **10** or **15**).
*   **Safety:** This is a critical safety parameter for long-distance autonomous voyages.