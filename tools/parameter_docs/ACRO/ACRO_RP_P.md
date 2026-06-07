---
layout: parameter
name: ACRO_RP_P
display_name: Acro Mode Roll/Pitch Gain
description: Converts pilot roll and pitch stick input into a target rotation rate in Acro mode.
default_value: 4.5
range: 1.0 10.0
units: 
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Acro Mode Roll/Pitch Gain (ACRO_RP_P)

## Description
`ACRO_RP_P` defines how fast the drone flips and rolls when in **Acro** mode.

A higher value increases the rotation rate for a given stick deflection. This is the primary parameter for adjusting the "Feel" of an FPV racing or freestyle drone.

## Tuning & Behavior
*   **Default:** 4.5.
*   **Usage:** For smooth cinematic flight in Acro, use a lower value (**2.0 to 3.0**). For aggressive freestyle, use a higher value (**6.0+**).
*   **Note:** This is functionally similar to "Rates" in Betaflight.