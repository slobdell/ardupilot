---
layout: parameter
name: FBWB_ELEV_REV
display_name: "Fly By Wire elevator reverse"
description: "Reverse elevator direction in FBWB/Cruise altitude control"
default_value: 0
range: 0 1
units: ""
group: FBWB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L328
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Fly By Wire elevator reverse (FBWB_ELEV_REV)

## Description
This parameter reverses the "Stick-to-Altitude" logic in assisted flight modes (FBWB, CRUISE).
*   **Standard (0):** Pulling back on the stick commands a climb (increase altitude).
*   **Reversed (1):** Pulling back on the stick commands a descent (decrease altitude).

## The Mathematics
Multiplier on Pilot Input.

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`. This is *not* the servo reversal (`SERVOx_REVERSED`); it is the logic reversal for the altitude controller's setpoint generation.

## Tuning & Behavior
*   **Default Value:** 0 (Standard)
*   **Warning:** Changing this to 1 is non-standard for aviation and extremely confusing for most pilots. Only use if you have a very specific, non-standard control interface.