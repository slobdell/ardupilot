---
layout: parameter
name: SUPER_SIMPLE
display_name: "Super Simple Mode"
description: "Bitmask to enable Super Simple mode for specific flight mode switch positions"
default_value: 0
range: 0 63
units: "Bitmask"
group: SUPER
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L179
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Super Simple Mode (SUPER_SIMPLE)

## Description
**Super Simple Mode** is a pilot assistance feature where the controls are always relative to the pilot's position (Home), regardless of the copter's heading or its position relative to the pilot. This differs from standard "Simple Mode" (which is just relative to heading). In Super Simple Mode, pushing the stick "Away" always makes the copter fly further away from Home, and pulling "Back" brings it home, even if it flies behind you.

## The Mathematics
The control inputs are rotated based on the bearing from Home to the Vehicle.
$$ \theta_{\text{pilot}} = \text{atan2}(P_{\text{veh}} - P_{\text{home}}) $$

## The Engineer's View
Defined in `ArduCopter/Parameters.cpp`. The parameter is a bitmask corresponding to the 6 Flight Mode switch positions (PWM ranges) on the RC transmitter.
*   **Bit 0:** Flight Mode 1
*   **Bit 1:** Flight Mode 2
*   ...
*   **Bit 5:** Flight Mode 6

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Setup:** Enable specific bits to activate Super Simple Mode only when that flight mode is selected.
*   **Warning:** Requires a valid GPS lock and Home position.