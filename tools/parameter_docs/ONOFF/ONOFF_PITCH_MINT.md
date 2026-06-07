---
layout: parameter
name: ONOFF_PITCH_MINT
display_name: "Pitch minimum movement time"
description: "Minimum activation time for pitch motor"
default_value: 0.1f
range: 0 2
units: "s"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L139
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Pitch minimum movement time (ONOFF_PITCH_MINT)

## Description
This parameter sets the minimum duration (pulse width) for activating the pitch motor in an On/Off tracker system. It prevents rapid switching or "chattering" that could damage relays or motors when small corrections are requested. If the calculated movement time is less than this value, the motor will not move at all (deadband effect) or will move for at least this long.

## The Mathematics
$$ \text{Pulse Width} = \max(\text{Calculated Time}, \text{ONOFF_PITCH_MINT}) $$
*(If correction < deadband, output is 0).*

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp`. Acts as a hysteresis or minimum actuation constraint.

## Tuning & Behavior
*   **Default Value:** 0.1 s
*   **Increase:** If relays click too rapidly or motors heat up.