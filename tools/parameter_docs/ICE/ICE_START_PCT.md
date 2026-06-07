---
layout: parameter
name: ICE_START_PCT
display_name: Throttle Percentage for Engine Start
description: The throttle opening percentage commanded during the cranking phase.
default_value: 5
range: 0 100
units: %
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L106
---

# Throttle Percentage for Engine Start (ICE_START_PCT)

## Description
`ICE_START_PCT` defines the "Start Throttle" – the position the carburetor or butterfly valve moves to when the starter motor is spinning.

Most gas engines require a small amount of throttle opening to draw in enough air and fuel to fire. If this value is too low, the engine will crank but never catch. If it is too high, the engine might "Scream" or surge immediately upon starting, which can be dangerous on the ground.

## Tuning & Behavior
*   **Default Value:** 5%.
*   **Tuning:** Increase this in 2% increments if the engine fails to start while cranking.
*   **Safety:** Ensure the drone is secured or the propeller is clear, as the engine will immediately move to this power level during the start sequence.