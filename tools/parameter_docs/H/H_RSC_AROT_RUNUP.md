---
layout: parameter
name: H_RSC_AROT_RUNUP
display_name: Autorotation Bailout Runup Time
description: The estimated time (in seconds) for the main rotor to reach full flying RPM after power is re-engaged.
default_value: 3.0
range: 1.0 10.0
units: s
group: H
visual_asset_id: heli_rsc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Autorotation/RSC_Autorotation.cpp#L46
---

# Autorotation Bailout Runup Time (H_RSC_AROT_RUNUP)

## Description
`H_RSC_AROT_RUNUP` is a safety timer for autonomous flight.

It tells the autopilot how long it must wait for the head speed to recover before it is allowed to increase the collective pitch. If the autopilot tries to climb before the rotor is back up to speed, the extra drag will "Bog" the motor and likely cause a crash.

## Tuning & Behavior
*   **Default Value:** 3.0 seconds.
*   **Constraint:** Must be at least 1 second longer than [H_RSC_AROT_RAMP](H_RSC_AROT_RAMP.html).
