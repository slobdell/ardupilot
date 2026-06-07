---
layout: parameter
name: THROTTLE_NUDGE
display_name: "Throttle nudge enable"
description: "When enabled, allows pilot input to adjust airspeed or throttle in auto modes"
default_value: 1
range: 0 1
units: ""
group: THROTTLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L445
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Throttle nudge enable (THROTTLE_NUDGE)

## Description
This feature allows the pilot to "nudge" (override) the target airspeed or throttle setting during autonomous flight (Auto, Cruise, Loiter) simply by moving the throttle stick. It gives the pilot an intuitive way to speed up or slow down the aircraft without switching modes or changing parameters.

## The Mathematics
If `Throttle Stick` > 50%:
$$ \text{Target Airspeed} = \text{AIRSPEED\_CRUISE} + (\text{AIRSPEED\_MAX} - \text{AIRSPEED\_CRUISE}) \times \frac{\text{Stick}\% - 50}{50} $$

If no airspeed sensor:
$$ \text{Target Throttle} = \text{Base Throttle} + \text{Nudge Factor} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`. Logic resides in `ArduPlane/Events.cpp` or similar throttle loop.
*   **Enabled (1):** Pilot has authority to increase energy/speed.
*   **Disabled (0):** Stick position is ignored in auto-throttle modes.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Safety:** Useful for flying into strong headwinds where the cruise airspeed might be insufficient.