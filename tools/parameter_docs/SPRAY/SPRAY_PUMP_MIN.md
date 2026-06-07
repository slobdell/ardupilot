---
layout: parameter
name: SPRAY_PUMP_MIN
display_name: Sprayer Pump Speed Minimum
description: The minimum pump duty cycle (as a percentage) to ensure consistent flow.
default_value: 0
range: 0 100
units: '%'
group: SPRAY
visual_asset_id: sprayer_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Sprayer/AC_Sprayer.cpp#L48
---

# Sprayer Pump Speed Minimum (SPRAY_PUMP_MIN)

## Description
`SPRAY_PUMP_MIN` sets the "Idle Speed" for your crop sprayer's pump.

Agricultural pumps often struggle to start or maintain pressure at very low throttle values. This parameter ensures that if the sprayer is active, the pump never drops below a certain speed, even if the drone is moving slowly.

## The Engineer's View
Defined in `AC_Sprayer.cpp`.
The sprayer logic calculates the required pump speed based on ground speed (`SPRAY_PUMP_RATE`).
$$ \text{Target Speed} = \text{Ground Speed} \times \text{SPRAY\_PUMP\_RATE} $$
This target is then clamped:
$$ \text{Output} = \max(\text{Target Speed}, \text{SPRAY\_PUMP\_MIN}) $$

This prevents the pump from stalling or pulsing when the drone slows down for a turn.

## Tuning & Behavior
*   **Default Value:** 0%.
*   **Recommendation:** Set to the lowest percentage where your pump still produces a clean spray pattern (e.g., **10% or 15%**).