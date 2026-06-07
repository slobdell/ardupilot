---
layout: parameter
name: SPRAY_SPEED_MIN
display_name: Sprayer Minimum Speed
description: The ground speed (in cm/s) above which the sprayer will automatically turn on.
default_value: 100
range: 0 1000
units: cm/s
group: SPRAY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Sprayer/AC_Sprayer.cpp#L45
---

# Sprayer Minimum Speed (SPRAY_SPEED_MIN)

## Description
`SPRAY_SPEED_MIN` prevents "Chemical Dumping" while the drone is moving too slowly.

In agricultural spraying missions, you want a uniform application of fertilizer or pesticide. If the drone is hovering or just starting to move, the sprayer would apply too much chemical to a single spot. This parameter ensures the pump only turns on when the drone has reached a safe, productive ground speed.

## Tuning & Behavior
*   **Default:** 100 cm/s (1.0 m/s).
*   **Recommendation:** Set this to your minimum effective spraying speed.
*   **Physics:** This acts as a logical gate. Below this speed, the pump is OFF. Above this speed, the pump is ON (or modulated based on [SPRAY_PUMP_RATE](SPRAY_PUMP_RATE.html)).