---
layout: parameter
name: SIMPLE
display_name: "Simple mode bitmask"
description: "Bitmask to enable Simple Mode for specific flight mode switch positions"
default_value: 0
range: 0 63
units: "Bitmask"
group: SIMPLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L305
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Simple mode bitmask (SIMPLE)

## Description
**Simple Mode** is a pilot assistance feature where the controls are relative to the copter's heading *when it was armed* (or last reset). This means "Forward" on the stick always moves the copter North (if you armed facing North), even if the copter rotates to face East. It is "Headless Mode" (orientation independent).

## The Mathematics
The control inputs are rotated by the difference between the current heading and the initial heading $\psi_0$.

## The Engineer's View
Defined in `ArduCopter/Parameters.cpp`.
*   **Bit 0:** Flight Mode 1
*   **Bit 1:** Flight Mode 2
*   ...
*   **Bit 5:** Flight Mode 6

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Vs Super Simple:** Simple Mode only handles orientation. Super Simple handles orientation AND position relative to home.