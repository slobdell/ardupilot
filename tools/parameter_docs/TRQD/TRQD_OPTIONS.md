---
layout: parameter
name: TRQD_OPTIONS
display_name: Torqeedo Integration Options
description: Bitmask of advanced settings for Torqeedo motor control.
default_value: 1
range: 0 1
units: 
group: TRQD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp#L36
---

# Torqeedo Integration Options (TRQD_OPTIONS)

## Description
`TRQD_OPTIONS` is a bitmask to enable specific communication behaviors with the Torqeedo Tiller or motor controller.

*   **Bit 0 (1): Reverse Direction.** If set, the forward/reverse logic of the Torqeedo motor is swapped at the protocol level.

## Tuning & Behavior
*   **Default:** 1.
*   **Usage:** Enable Bit 0 if your boat moves backward when the autopilot commands forward speed.