---
layout: parameter
name: PILOT_THR_BHV
display_name: Pilot Throttle Behavior
description: Bitmask for various options relating to throttle stick interpretation.
default_value: 0
range: 0 1
units: 
group: PILOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Pilot Throttle Behavior (PILOT_THR_BHV)

## Description
`PILOT_THR_BHV` allows you to customize how the autopilot interprets your throttle stick, particularly useful for "Self-Centering" transmitters.

*   **Bit 0 (1): Center-Thrust.** Use this if your transmitter's throttle stick has a spring and always returns to the center (common on DJI-style or consumer controllers). When enabled, the drone assumes "Neutral" is in the middle of the stick's travel. This allows for easier altitude hold and prevents the drone from accidentally landing or jumping if you let go of the stick.

## Tuning & Behavior
*   **Default:** 0 (Standard throttle - 0% at bottom).
*   **Recommendation:** Only enable if you have a physical spring on your throttle stick.