---
layout: parameter
name: AROT_RAMP
display_name: Autorotation Bailout Ramp Time
description: Time in seconds to ramp motors when bailing out of autorotation.
default_value: 2
range: 
units: s
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/RSC_Autorotation.cpp
---

# Autorotation Bailout Ramp Time (AROT_RAMP)

## Description
Defines the duration of the motor power ramp-up when the pilot or autopilot "bails out" of an autorotation and returns to powered flight.

## Tuning & Behavior
*   **Default Value:** 2 s
*   **Ensures a smooth but timely restoration of power without overstressing the drive system.**